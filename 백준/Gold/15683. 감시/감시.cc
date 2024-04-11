#include <iostream> // For cin, cout, and ios
#include <vector>   // For vector
#include <cstring>  // For memcpy

using namespace std;

int N,M;
int board[10][10];
// 북 동 남 서
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

vector<pair<int, pair<int,int>>> cctv;

int cctv_size;
int result=0;

void laser(int y, int x, int dir, int prove){
    dir = dir%4;
    while(true){
        y = y + dy[dir];
        x = x + dx[dir];
        if(y<0 || x <0 || y>N-1 || x>M-1 || board[y][x]==6) break;
        if(board[y][x] <= 0){
            board[y][x] += prove;
        }
        else continue;
    }
    return;
}

void DFS(int count){
    if(count == cctv_size){
        int cnt = 0;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                // 사각지대가 아닌 경우를 셈 (그럼 이 최대크기 구하면 됨)
                if(board[i][j] != 0) cnt++;
            }
        }
        if(result < cnt) result = cnt;
        return;
    }

    int cctv_number = cctv[count].first;
    int y = cctv[count].second.first;
    int x = cctv[count].second.second;

    if(cctv_number == 1){
        for(int dir = 0 ; dir<4;dir++){
            laser(y,x,dir,-1);
            DFS(count+1);
            laser(y,x,dir,+1);
        }
    }
    else if(cctv_number == 2){
        for(int dir = 0 ; dir<2;dir++){
            laser(y,x,dir,-1);
            laser(y,x,dir+2,-1);
            DFS(count+1);
            laser(y,x,dir,+1);
            laser(y,x,dir+2,+1);
        }
    }
    else if(cctv_number == 3){
        for(int dir = 0 ; dir<4;dir++){
            laser(y,x,dir,-1);
            laser(y,x,dir+1,-1);
            DFS(count+1);
            laser(y,x,dir,+1);
            laser(y,x,dir+1,+1);
        }

    }
    else if(cctv_number == 4){
        for(int dir = 0 ; dir<4;dir++){
            laser(y,x,dir,-1);
            laser(y,x,dir+1,-1);
            laser(y,x,dir+2,-1);
            DFS(count+1);
            laser(y,x,dir,+1);
            laser(y,x,dir+1,+1);
            laser(y,x,dir+2,+1);
        }

    }
    else if(cctv_number == 5){
            laser(y,x,0,-1);
            laser(y,x,1,-1);
            laser(y,x,2,-1);
            laser(y,x,3,-1);
            DFS(count+1);
            laser(y,x,0,1);
            laser(y,x,1,1);
            laser(y,x,2,1);
            laser(y,x,3,1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int y = 0 ; y < N ; y ++){
        for(int x = 0 ; x < M ; x++){
            int n;
            cin >> n;
            board[y][x]=n;
            if(n!=0 && n!=6){
                cctv.push_back({n,{y,x}});
            }
        }
    }
    cctv_size = cctv.size();

    DFS(0);
    cout<<N*M - result;
    return 0;
}