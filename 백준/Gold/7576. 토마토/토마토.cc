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
    int M,N;
    cin >> M >> N;
    int board[1002][1002];
    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0}; // 오 왼 아래 위
    queue<pair<int,int>> Q;
    // M : 가로
    for(int i = 0 ; i < N ; i ++){
        for( int j = 0 ; j < M ; j ++ ){
            int number;
            cin >> number;
            // 토마토가 익은 경우 Q에 넣음
            if(number == 1) Q.push({i,j});
            board[i][j] = number;
        }
    }
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
		Q.pop();
        for(int dir = 0 ; dir < 4 ; dir ++){
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(board[ny][nx] != 0) continue;
            board[ny][nx] = board[cur.first][cur.second]+1;
            Q.push({ny,nx});
        }
    }
    int max = 0; 
    for(int i = 0 ; i < N;i++){
        for(int j = 0 ; j < M ; j ++){
            if(board[i][j] == 0){
                cout << -1;
                return 0;
            }
            if(max < board[i][j] ) max = board[i][j];
        }
    }
    cout << max-1;
    return 0;
}
