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
    int Test,M,N,K;
    int dy[4] ={0,0,-1,1};
    int dx[4] = {1,-1,0,0};
    cin >> Test;
    queue<int> count_q;
    for(int t = 0 ; t < Test; t++){
        //M이 가로임

        cin >> M >> N >> K;
        int board[51][51];
        int visit[51][51];
        int count=0;

        for(int i = 0; i < N;i++){
            fill(board[i],board[i]+M,0);
            fill(visit[i],visit[i]+M,0);
        }

        queue<pair<int,int>> Q;
        // 보드에 채움
        for(int i = 0 ; i < K ; i ++){
            int x,y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        // 실제로 모든 녀석들 본다.
        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < M ; j ++){
                if(visit[i][j]==1 || board[i][j]==0) continue;

                Q.push({i,j});
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        if(ny<0||ny>=N||nx<0||nx>=M) continue;
                        if(visit[ny][nx] ==1) continue;
                        if(board[ny][nx] ==0) continue;
                        visit[ny][nx] = 1;
                        Q.push({ny,nx});
                    }
                    if(Q.empty()) {
                        count++;
                    }
                }
            }
        }
        cout<<count<<'\n';
    }
    return 0;
}
