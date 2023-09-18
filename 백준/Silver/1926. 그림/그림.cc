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
    int arr[501][501];
    int n,m;
    cin >> n>>m;
    bool visit[501][501]={0};
    int dx[4] = {1, 0, -1, 0}; // 오른쪽, 아래, 왼쪽, 위쪽
    int dy[4] = {0, 1, 0, -1};
    for(int i = 0 ; i < n ; i++){
        for(int j=0; j < m ; j ++){
            int number;
            cin >> number;
            arr[i][j] = number;
        }
    }
    int count = 0;
    int max = 0;
    queue<pair<int,int>> Q;
    for(int y = 0 ; y < n ; y ++){
        for(int x = 0 ; x < m ; x ++){
            // 방문했거나 그림이 없으면 바로 넘겨
            if(visit[y][x] == 1 || arr[y][x] != 1) continue;
            visit[y][x] = 1;
            Q.push({y,x});
            int cur_max=0;
            while(!Q.empty()){
                cur_max++;
                pair<int,int> cur = Q.front();
                Q.pop();
                for(int dir = 0 ; dir < 4; dir++){
                    int ny = cur.first + dy[dir];
                    int nx = cur.second + dx[dir];
                    if(ny<0 || ny>=n || nx <0 || nx>=m) continue;
                    if(visit[ny][nx] == 0 && arr[ny][nx] == 1) {
                        visit[ny][nx] = 1;
                        Q.push({ny,nx});
                    }
                }
            }
            if(max<cur_max) max = cur_max;
            if(cur_max>0) count++;
        }
    }
    cout<<count<<'\n'<<max;

    return 0;
}
