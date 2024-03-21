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

    int board[1001][1001]={0};
    bool vis[1001][1001]={0};
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<pair<int,int>> Q;
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            int num;
            cin >> num;
            if(num==2) {Q.push({i,j}); board[i][j]=0;vis[i][j]=true;}
            else if(num == 1) board[i][j]=-1;
            else if(num==0) board[i][j]=0;
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i = 0 ; i < 4 ; i ++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx <0 || ny <0 || nx>n || ny>m) continue;
            if(vis[nx][ny]) continue;

            if(board[nx][ny]==0) continue;
            if(board[nx][ny]==-1) board[nx][ny] = board[cur.first][cur.second] + 1;
            Q.push({nx,ny});
            vis[nx][ny] = true;
        }
    }

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            cout<<board[i][j] <<' ';
        }
        cout<<'\n';
    }


    return 0;
}


