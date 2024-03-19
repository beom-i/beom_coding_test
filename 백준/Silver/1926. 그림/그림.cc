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
    bool board[501][501]={0};
    bool visit[501][501]={0};
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int N, M;
    cin >> N >> M;
    for(int i = 1;i <= N;i++){
        for(int j = 1 ;j <=M;j++){
            int num;
            cin >> num;
            board[i][j]=num;
        }
    }

    queue<pair<int,int>> Q;
    int entire_count = 0; //  전체 그림 개수
    int max_area = 0;
    for(int i = 1 ; i <=N;i++){
        for(int j = 1 ; j <=M ; j++){
            // 보드에 1이고, 방문한 적 없으면
            if(visit[i][j]==0 && board[i][j]==1){
                entire_count++;
                int cur_area=0;
                Q.push({i,j});
                visit[i][j]=1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front();Q.pop();
                    for(int c = 0 ; c <4 ; c ++){
                        int nx = cur.first + dx[c];
                        int ny = cur.second + dy[c];
                        // 범위 밖
                        if(nx<0 || nx > N || ny <0 || ny>M) continue;
                        // 방문했거나, 보드에 없으면 넣지 않음
                        if(visit[nx][ny]==1 || board[nx][ny]!=1) continue;
                        visit[nx][ny]=1;
                        Q.push({nx,ny});
                    }
                    cur_area++;
                }
                if(max_area<cur_area){max_area = cur_area;}
                
            }
        }
    }

    cout<<entire_count<<'\n'<<max_area;

    return 0;
}
