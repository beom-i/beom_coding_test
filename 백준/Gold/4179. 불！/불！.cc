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

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int R,C;
    cin >> R >>C;
    int jihun_board[1001][1001];
    int fire_board[1001][1001];
    for(int i = 0 ; i < R ; i ++){
        fill(jihun_board[i],jihun_board[i]+C,-1);
        fill(fire_board[i],fire_board[i]+C,-1);
    }
    queue<pair<int,int>> jihun;
    queue<pair<int,int>> fire;
    int dy[4] ={0,0,-1,1};
    int dx[4] ={1,-1,0,0};
    for(int i = 0 ; i < R ; i ++){
        for(int j = 0 ; j < C ; j++){
            char c;
            cin >> c;
            if(c == '#') {
                jihun_board[i][j] = -1;
                fire_board[i][j] = -1;
            }
            else if(c=='J') {
                jihun_board[i][j] = 1;
                fire_board[i][j] = 0;
                jihun.push({i,j});
            }
            else if(c=='F') {
                jihun_board[i][j] = 0;
                fire_board[i][j] = 1;
                fire.push({i,j});
            }
            // 벽, 지훈, 불 셋이 아닌 경우 = 지나갈 수 있음
            else if(c=='.') {
                jihun_board[i][j] = 0;
                fire_board[i][j] = 0;
            }
        }
    }

    while(!fire.empty()){
        pair<int,int> cur = fire.front();
        fire.pop();
        for(int dir = 0 ; dir<4;dir++){ 
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny<0||ny>=R||nx<0||nx>=C) continue;
            // 벽만나면
            if(fire_board[ny][nx]== -1) continue;
            // 방문했다면
            if(fire_board[ny][nx] > 0) continue;
            fire_board[ny][nx] = fire_board[cur.first][cur.second]+1;
            fire.push({ny,nx});
        }
    }
    while(!jihun.empty()){
        pair<int,int> cur = jihun.front();
        jihun.pop();
        for(int dir=0; dir<4;dir++){
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny<0||ny>=R||nx<0||nx>=C){
                cout << jihun_board[cur.first][cur.second];
                return 0;
            }
            if(jihun_board[ny][nx] >0 || jihun_board[ny][nx]==-1) continue;
            if(jihun_board[cur.first][cur.second]+1>=fire_board[ny][nx] && fire_board[ny][nx] !=0) continue;
            jihun_board[ny][nx] = jihun_board[cur.first][cur.second]+1;
            jihun.push({ny,nx});
        }
    }
    cout<<"IMPOSSIBLE";
}
