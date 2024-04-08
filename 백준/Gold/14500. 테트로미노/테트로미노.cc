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
int board[502][502]={0};
bool visited[502][502]={0};
int result=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void DFS(int y, int x, int depth, int sum){

    if(depth == 3){
        if(result<sum) result=sum;

        return;
    }
    for(int dir = 0 ; dir < 4 ; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx<0 || ny <0 || nx>=M || ny>=N || visited[ny][nx]) continue;

        visited[ny][nx]=true;
        DFS(ny,nx,depth+1,sum+board[ny][nx]);
        visited[ny][nx]=false;
    }
}
// ㅏ
void shape1(int y,int x){
    int sum=0;
    sum = board[y][x] + board[y-1][x] + board[y+1][x] + board[y][x+1];
    if(result<sum)result=sum;
    return;
}
// ㅓ
void shape2(int y,int x){
    int sum=0;
    sum = board[y][x] + board[y-1][x] + board[y+1][x] + board[y][x-1];
    if(result<sum)result=sum;
    return;
}
// ㅗ
void shape3(int y,int x){
    int sum=0;
    sum = board[y][x] + board[y][x-1] + board[y][x+1] + board[y-1][x];
    if(result<sum)result=sum;
    return;
}
// ㅜ
void shape4(int y,int x){
    int sum=0;
    sum = board[y][x] + board[y][x-1] + board[y][x+1] + board[y+1][x];
    if(result<sum)result=sum;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M; 
    
    for(int i = 0 ; i < N ; i ++){
        for(int l = 0 ; l < M ; l ++){
            int n;
            cin >> n;
            board[i][l] = n;
        }
    }
    for(int y = 0 ; y < N ; y ++){
        for(int x = 0 ; x < M ; x ++){
            visited[y][x]=true;
            DFS(y,x,0,board[y][x]);
            visited[y][x]=false;
            if(y >= 1 && y < N-1 && x < M-1) shape1(y,x);
            if(y >= 1 && y < N-1 && x >= 1) shape2(y,x);
            if(x >= 1 && x < M-1 && y >= 1) shape3(y,x);
            if(x >= 1 && x < M-1 && y < N-1) shape4(y,x);
        }
    }

    cout<<result;
    return 0;

}