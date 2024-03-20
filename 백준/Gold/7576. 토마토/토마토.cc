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

    queue<pair<int,int>> Q;
    int board[1001][1001] ={-1};
    int width,length;
    cin >> width >> length;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    for(int i = 1 ; i <= length;i++){ 
        for(int j = 1 ; j <= width; j++){
            int num;
            cin>>num;
            board[i][j] = num;
            if(num == 1) Q.push({i,j});
        }
    }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i = 0 ; i < 4 ; i ++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 1 || ny < 1 || nx > length || ny > width) continue;
            if(board[nx][ny]!=0) continue;
            board[nx][ny] = board[cur.first][cur.second]+1;
            Q.push({nx,ny});
            // for(int i = 1;i<=length;i++){
            //     for(int j = 1 ; j <= width; j++){
            //         cout<<board[i][j];
            //     }
            //     cout<<'\n';
            // }
        }
    }
    int max = 0;
    for(int i = 1 ; i <= length;i++){ 
        for(int j = 1 ; j <= width; j++){
            if(board[i][j]==0) {cout<<-1;return 0;}
            if(max<board[i][j]) max = board[i][j];
        }
    }
    cout<<max-1;
    return 0;
}


