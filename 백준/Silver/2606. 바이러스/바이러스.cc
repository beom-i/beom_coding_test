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
    int computer;
    int board[102][102]={0};
    int visit[102]={0};
    int n;
    cin>>computer>>n;
    queue<pair<int,int>> Q;

    for(int i = 0 ; i < n; i ++){
        int x,y;
        cin >> x >> y;
        board[x][y] = 1;
        board[y][x] = 1;
    }

    //시작점은 0,0 1번 컴퓨터임
    visit[1] = 1;
    Q.push({1,1});
    int count=0;

    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        int dy = cur.first;
        int dx = cur.second;
        for(int c = 1 ; c <= computer;c++){
            if(board[c][dy] == 1){
                if(visit[c] == 0){
                    visit[c] = 1;
                    Q.push({c,dy});
                    count++;
                }
            }
        }
    }
    cout<<count;

    return 0;
}
