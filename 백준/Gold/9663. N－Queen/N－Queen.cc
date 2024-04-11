#include <iostream> // For cin, cout, and ios
#include <vector>   // For vector
#include <cstring>  // For memcpy

using namespace std;

// int board[17][17];
int noused[17][17];
int N;
int result=0;

void laser(int y,int x,int prove){
    for(int i = 0 ; i < N ; i ++){
        if(y+i <= N-1){
            noused[y+i][x]+=prove;
            if(x+i <= N-1){
                noused[y+i][x+i]+=prove;
            }
            if( x - i >=0){
                noused[y+i][x-i]+=prove;
            }   
        }
    }
    return;
}

void DFS(int y){
    if(y == N){
        result++;
        return;
    }
    for(int x = 0 ; x < N ; x++){
        if(noused[y][x]) continue;
        laser(y,x,1);
        DFS(y+1);
        laser(y,x,-1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    DFS(0);
    cout<<result;
    return 0;
}