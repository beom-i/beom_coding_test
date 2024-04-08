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

    
int N,M;
int board[10][10]={0};
int empty_count=0;
int result;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int virus_count;
int copy_board[10][10];

void DFS(int y, int x){
    for(int dir=0;dir<4;dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny<0||nx<0||ny>N-1||nx>M-1) continue;
        if(copy_board[ny][nx]==1 || copy_board[ny][nx]==2) continue;
        copy_board[ny][nx]=2;
        virus_count++;
        DFS(ny,nx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    // 1. 연구소는 빈칸, 벽으로 이루어짐
    // 2. 일부 칸에 바이러스 존재, 상하좌우로 인접 빈 칸으로 퍼져나간다.
    // 3. 새로 세울 수 있는 벽의 개수는 3개, 꼭 3개를 세워야한다.

    // 0 : 빈칸 / 1 : 벽 / 2 : 바이러스
    // memcpy(copy, original, sizeof(original));

    deque<pair<int,int>> virus;
    deque<pair<int,int>> empty;
    cin>>N>>M;
    for(int y = 0 ; y < N; y++){
        for(int x = 0 ; x < M ; x++){
            int n;
            cin >> n;
            if(n==0){
                empty_count++;
                empty.push_back({y,x});
            }
            else if(n==2){
                virus.push_back({y,x});
            }
            board[y][x]=n;
        }
    }

    for(int a = 0;a<empty.size();a++){
        for(int b = a+1;b<empty.size();b++){
            for(int c= b+1;c<empty.size();c++){
                // 벽 세움
                board[empty[a].first][empty[a].second]=1;
                board[empty[b].first][empty[b].second]=1;
                board[empty[c].first][empty[c].second]=1;

                virus_count=0;
                memcpy(copy_board,board,sizeof(board));
                for(int i = 0 ; i < virus.size();i++){
                    DFS(virus[i].first,virus[i].second);
                }
                if(result<empty_count - virus_count)result = empty_count - virus_count;

                board[empty[a].first][empty[a].second]=0;
                board[empty[b].first][empty[b].second]=0;
                board[empty[c].first][empty[c].second]=0;
            }
        }
    }
    cout<<result-3;

    return 0;

}