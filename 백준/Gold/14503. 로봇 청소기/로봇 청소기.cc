#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <iomanip>
#include <set>
#include <map>
#include <deque>
#include <utility>

using namespace std;

// 바라보는 방향 180도 회전
int see180(int d){
    if(d==0) return 2;
    else if(d==1) return 3;
    else if(d==2) return 0;
    else return 1;
}
// 바라보는 방향 반시계 방향 90도 회전
int see90(int d){
    if(d==0) return 3;
    else if(d==1) return 0;
    else if(d==2) return 1;
    else return 2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int board[51][51]={0};
    /*
     * 1. 현재 칸이 청소되지 않았으면 현재 칸 청소
     * 2-1. 주변 4칸 중 청소되지 않은 빈칸이 없으면
     *    2-1-1. 바라보는 방향에서 한칸 후진한 후 1번으로 돌아감
     *    2-1-2. 바라보는 방향에서 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
     * 2-2. 주변 4칸 중 청소되지 않은 빈칸이 있으면
     *    2-2-1. 반시계 방향으로 90도 회전
     *    2-2-2. 바라보는 방향으로 앞쪽칸이 청소되지 않은 빈칸인 경우 한 칸 전진하고 1번으로 돌아감
     */
    int N, M, x, y, d;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    cin >> N >> M;
    cin >> y >> x >> d;

    // board 에 저장
    for(int i = 0 ; i < N ; i ++){
        for(int l = 0 ; l < M ; l ++){
            int n;
            cin >> n;
            board[i][l] = n;
        }
    }
    int count=0;
    while(true){
        // 1. 현재 칸이 청소되지 않았으면 현재 칸 청소
        if(board[y][x] == 0) {count++; board[y][x] = 2;}

        bool valid = true;
        // 2. 주변 4칸 중 청소되지 않은 빈칸 탐색
        for(int dir = 0 ; dir < 4 ; dir ++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            // 한개라도 빈칸이 있으면
            if(board[ny][nx] == 0) valid = false;
        }
        
        //  2-1. 주변 4칸 중 청소되지 않은 빈칸이 없으면
        if(valid){
            d = see180(d);
            int nx = x + dx[d];
            int ny = y + dy[d];
            //  2-1-2. 바라보는 방향에서 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
            if(board[ny][nx] == 1) break;
            //  2-1-1. 바라보는 방향에서 한칸 후진한 후 1번으로 돌아감
            else {
                x = nx;
                y = ny;
                d = see180(d);
                continue;
            }
        }
        // 2-2. 주변 4칸 중 청소되지 않은 빈칸이 있으면
        else{
            while(true){
                // 2-2-1. 반시계 방향으로 90도 회전
                d = see90(d);
                int nx = x + dx[d];
                int ny = y + dy[d];
                // 2-2-2. 바라보는 방향으로 앞쪽칸이 청소되지 않은 빈칸인 경우 한 칸 전진하고 1번으로 돌아감
                if(board[ny][nx] == 0){
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }
    }

    cout<<count;
    return 0;

}

