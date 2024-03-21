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

    struct Node{
        int x; int y; int z;
    };

    queue<Node> Q;

    int board[101][101][101]={0};
    bool vis[101][101][101]={0};
    int dx[6] = {1,0,0,-1,0,0};
    int dy[6] = {0,1,0,0,-1,0};
    int dz[6] = {0,0,1,0,0,-1};

    int M,N,H;
    cin >> M >> N >> H;

    for(int z = 0 ; z < H;z++){
        for(int x = 0 ; x < N ; x++){
            for(int y = 0 ; y < M ; y++){
                int num;
                cin >> num;
                board[z][x][y] = num;
                if(num ==1) {Q.push({x,y,z}); vis[z][x][y]= true;}
            }
        }
    }

    while(!Q.empty()){
        auto cur = Q.front();Q.pop();
        for(int i = 0 ; i < 6 ;i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];
            if(nx<0 || ny<0 || nz<0 || nx>=N || ny>=M || nz>=H) continue;
            if(board[nz][nx][ny]==-1 || board[nz][nx][ny]==1 || vis[nz][nx][ny]) continue;
            Q.push({nx,ny,nz});
            board[nz][nx][ny] = board[cur.z][cur.x][cur.y]+1;
            vis[nz][nx][ny] = true;
        }
    }

    int max=0;
    for(int z = 0 ; z < H;z++){
        for(int x = 0 ; x < N ; x++){
            for(int y = 0 ; y < M ; y++){
                if(board[z][x][y]==0) {cout<<-1;return 0;}
                if(max<board[z][x][y]) max=board[z][x][y];
            }
        }
    }
    cout<<max-1;
    return 0;
}

