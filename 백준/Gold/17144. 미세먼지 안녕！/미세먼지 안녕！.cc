#include <iostream> // For cin, cout, and ios
#include <vector>   // For vector
#include <cstring>  // For memcpy
#include <stdlib.h> // For abs
#include <algorithm>  // For sort

using namespace std;

int R,C,T; // 방 : R x C / T : T 초 후
int CURRENT[51][51]; // 현재 미세먼지 양
int FUTURE[51][51];  // 미세먼지 이동이 반영되는

// 공기 청정기 y좌표 - (clean_y,0) , (clean_y+1,0)
int clean_y = -1;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

// // 동 북 서 남
// int upx[4]={1,0,-1,0};
// int upy[4]={0,-1,0,1};

// // 동 남 서 북
// int downx[4]={1,0,-1,0};
// int downy[4]={0,1,0,-1};

void MISE(){
    for(int y = 0 ; y <R ; y++){
        for(int x = 0 ; x < C ; x++){
            // 미세먼지가 존재하면
            if(CURRENT[y][x]!=0 && CURRENT[y][x]!=-1){
                int sum = 0;
                for(int dir=0;dir<4;dir++){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    // 범위 밖이면 확산 X
                    if(ny<0 || nx<0 || ny > R-1 || nx > C-1) continue;
                    // 공기청정기면 확산 X
                    if(CURRENT[ny][nx] == -1) continue;

                    // 현재 위치에서 /5만큼 확산시킴
                    FUTURE[ny][nx] += CURRENT[y][x]/5;
                    // 확산시킨 만큼 미래의 반영되는 것도 줄어듬
                    FUTURE[y][x] -=CURRENT[y][x]/5;
                }
            }
        }
    }
    // memcpy(destination, source, source 의 크기)
    memcpy(CURRENT,FUTURE,sizeof(FUTURE));
}

void CLEAN(){
    // 1. 위쪽
    int y = clean_y;
    int x = 0;

    // 청정기의 가로 경로 다 깔끔하기 밀기
    for(int x = 0 ; x < C ; x++){
        FUTURE[0][x] = 0;
        FUTURE[R-1][x] = 0;
        FUTURE[y][x] = 0;
        FUTURE[y+1][x] = 0;
    }
    // 청정기의 세로 경로 다 깔끔하게 밀기
    for(int y = 0 ; y < R ; y++){
        FUTURE[y][0] = 0;
        FUTURE[C-1][0] = 0;
    }

    // 1-1. 동쪽으로 밀기
    for(int i = 1 ; i < C ; i++){
        FUTURE[y][i+1] = CURRENT[y][i];
    }
    // 1-2. 북쪽으로 밀기
    for(int i = y ; i > 0 ; i--){
        FUTURE[i-1][C-1] = CURRENT[i][C-1];
    }
    // 1-3. 서쪽으로 밀기
    for(int i = C-1 ; i > 0 ; i--){
        FUTURE[0][i-1] = CURRENT[0][i];
    }
    // 1-4. 남쪽으로 밀기
    for(int i = 0 ; i < y-1 ; i++){
        FUTURE[i+1][0] = CURRENT[i][0];
    }

    // 2. 아래쪽
    y = clean_y+1;

    // 1-1. 동쪽으로 밀기
    for(int i = 1 ; i < C ; i++){
        FUTURE[y][i+1] = CURRENT[y][i];
    }
    // 1-2. 남쪽으로 밀기
    for(int i = y ; i < R-1 ; i++){
        FUTURE[i+1][C-1] = CURRENT[i][C-1];
    }
    // 1-3. 서쪽으로 밀기
    for(int i = C-1 ; i > 0 ; i--){
        FUTURE[R-1][i-1] = CURRENT[R-1][i];
    }
    // 1-4. 북쪽으로 밀기
    for(int i = R-1 ; i > y+1 ; i --){
        FUTURE[i-1][0] = CURRENT[i][0];
    }
    // // 공기청정기 다시 대입
    FUTURE[y-1][0] = -1;
    FUTURE[y][0] = -1;
    // memcpy(destination, source, source 의 크기)
    memcpy(CURRENT,FUTURE,sizeof(FUTURE));
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> T;
    
    for(int y = 0 ; y < R ; y ++){
        for(int x = 0 ; x < C ; x++){
            int n; cin>>n;
            CURRENT[y][x] = n;
            FUTURE[y][x] = n;
            if(n==-1 && clean_y==-1){
                clean_y = y;
            }
        }
    }
    
    // T초마다 발생
    for(int i = 0 ; i < T ; i++){
        MISE();
        CLEAN();
    }
    
    int result = 0;
    for(int y = 0 ; y < R ; y ++){
        for(int x = 0 ; x < C ; x++){
            // cout<<CURRENT[y][x] << ' ';
            if(CURRENT[y][x]>0) result+=CURRENT[y][x];
        }
        // cout<< '\n';
    }
    cout<<result;
    return 0;
}