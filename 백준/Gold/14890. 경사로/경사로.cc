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



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int board[101][101]={0}; 
    int N; // 2 ~ 100
    int L; // 1 ~ N
    // 높이는 1 ~ 10 

    cin >> N >> L;
    for(int y = 0 ; y < N ; y++){
        for(int x = 0 ; x < N ; x++){
            int height;
            cin >> height;
            board[y][x] = height;
        }
    }
    
    int result=0;

    for(int y = 0 ; y < N ; y ++){
        int standard = board[y][0];
        int life=0; // 올라갈 때 경사로 가능한지
        int time=0; // 내려갈 때 경사로 가능한지
        int count=0;
        for(int x =0 ; x < N ; x++ ){
            int height = standard-board[y][x];
            if(height!=0){
                // 높이가 1보다 크면 종료
                if(abs(height)>1) break;

                if(time!=0)break;
                if(height==1){
                    standard=board[y][x];
                    time=L-1;
                    life=0;
                }
                if(height==-1){
                    if(life<L) break;
                    life=1;
                    standard=board[y][x];
                }
            }
            if(height==0){
                if(time!=0) time--;
                else life++;
            }
            count++;
        }
        if(time==0 && count==N) {result++;}
    }

    for(int x = 0 ; x < N ; x ++){
        int standard = board[0][x];
        int life=0; // 올라갈 때 경사로 가능한지
        int time=0; // 내려갈 때 경사로 가능한지
        int count=0;
        for(int y =0 ; y< N ; y++ ){
            int height = standard-board[y][x];
            if(height!=0){
                // 높이가 1보다 크면 종료
                if(abs(height)>1) break;

                if(time!=0)break;
                if(height==1){
                    standard=board[y][x];
                    time=L-1;
                    life=0;
                }
                if(height==-1){
                    if(life<L) break;
                    life=1;
                    standard=board[y][x];
                }
            }
            if(height==0){
                if(time!=0) time--;
                else life++;
            }
            count++;
        }
        if(time==0 && count==N) {result++;}
    }
    cout<<result;
    return 0;
}