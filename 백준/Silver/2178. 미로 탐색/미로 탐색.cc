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
    int board[101][101];
    int n,m;
    cin >> n >> m;
    bool visit[101][101]={0};
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0}; // 오른쪽, 아래, 왼쪽, 위쪽
    int count_way[101][101];
    for(int i = 0 ; i < n ; i++){
        for(int j=0; j < m ; j ++){
            char cell;
            cin >> cell;
            board[i][j] = cell -'0';
        }
    }

    queue<pair<int,int>> Q;
    visit[0][0] = 1;
    Q.push({0,0});
    count_way[0][0] = 1;
    int prove = 0;
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir = 0 ; dir < 4 ; dir++){
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny<0 || ny>=n || nx <0 || nx >= m) continue;
            if(visit[ny][nx] == 1 || board[ny][nx] == 0) continue;
            visit[ny][nx] = 1;
            count_way[ny][nx] = count_way[cur.first][cur.second]+1;
            Q.push({ny,nx});
        }
    }
    cout << count_way[n-1][m-1];
    return 0;
}
