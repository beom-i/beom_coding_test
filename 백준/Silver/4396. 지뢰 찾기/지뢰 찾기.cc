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

    int count_board(char board[10][10],int i, int j,int n){
        int count = 0;
        if(board[i][j] == '*') return -1;
        if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == '*') count++;
        if(i-1 >= 0 && board[i-1][j] == '*') count++;
        if(i-1 >= 0 && j+1 < n && board[i-1][j+1] == '*') count++;
        if(j-1 >= 0 && board[i][j-1] == '*') count++;
        if(j+1 < n && board[i][j+1] == '*') count++;
        if(i+1 < n && j-1 >= 0 && board[i+1][j-1] == '*') count++;
        if(i+1 < n && board[i+1][j] == '*') count++;
        if(i+1 < n && j+1 < n && board[i+1][j+1] == '*') count++;
        return count;
    }
    
struct Point {
    int x;
    int y;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    map<int,int> mine;
    vector<Point> points;
    char board[10][10]={};
    // 1. 메인 보드 저장
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            char c;
            cin >> c;
            if( c== '*') {
                Point p ={i,j};
                points.push_back(p);

            }
            board[i][j] = c;
        }
    }

    // 2. 보드 누르기
    char output_board[10][10]={};
    bool minemode=false;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            char c;
            cin>>c;

            // 2-1. open
            if(c == 'x'){
                int count = count_board(board,i,j,n);
                // 지뢰 밟음
                if(count == -1) minemode=true;
                // 지뢰 아님
                output_board[i][j] = count + '0';
            }
            // 2-2. close
            if(c == '.'){
                output_board[i][j] = '.';
            }
        }
    }

    // 3. mine mode일 때 output_board에 지뢰 추가
    if(minemode){
        for(int i = 0 ; i < points.size();i++){
            output_board[points[i].x][points[i].y]='*';
        }
    }

    // 4. 출력
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            cout << output_board[i][j];
        }
        cout<<'\n';
    }
    return 0;
}