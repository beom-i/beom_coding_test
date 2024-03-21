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

    vector<string> board;
    bool vis[26][26]={0};
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    queue<pair<int,int>> Q;
    vector<int> output;
    output.push_back(1);
    int N;
    cin>>N;
    for(int i = 0 ; i < N;i++){
        string str;
        cin >> str;
        board.push_back(str);
    }
    // cout << board[0][1];

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            // 방문했거나, 보드에 집이 없는 경우(0)
            if(vis[i][j] || board[i][j]=='0') continue;
            int con=0;
            Q.push({i,j});
            vis[i][j]=true;
            while(!Q.empty()){
                con++;
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir<4;dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx<0 || ny <0 || nx >= N || ny >= N) continue;
                    if( board[nx][ny]=='0' || vis[nx][ny]) continue;
                    Q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
            output.push_back(con);
        }
    }
    cout<<output.size()-1<<'\n';
    sort(output.begin(),output.end());
    for(int i = 1; i <output.size();i++) cout<<output[i]<<'\n';
    return 0;
}


