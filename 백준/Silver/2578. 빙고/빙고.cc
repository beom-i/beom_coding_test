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

    map<int,int> board;
    int bingo[25]={0};
    int bingo_index=0;
    bool prove=false;

    // 1. 빙고 저장함
    // 빙고 불리는 값이 위치 i에 존재한다.
    for(int i = 0 ; i < 25 ; i ++){
        int number;
        cin >> number;
        board[number] = i;
    }

    // 2. 빙고를 부르는 과정
    for(int i = 0 ; i < 25 ; i ++){
        int number;
        cin >> number;
        bingo[board[number]]=1; // X 처리됨
        if(i>0){
            // 빙고 3개인지 판단
            int bingoCount=0;

            // 1 가로 판단
            
            for(int length = 0 ; length < 5 ; length ++){
                // 작은 빙고 판단
                int row=0; int col=0;
                for(int width = 0 ; width <5;width ++){
                    row = row + bingo[length*5 + width];
                    col = col + bingo[length + width*5];
                }
                if(row == 5) bingoCount++;
                if(col == 5) bingoCount++;
            }
            // 3 대각선 판단
            int width=0;
            int cross_bingo=0;
            for(int length = 0 ; length < 5 ; length++){
                cross_bingo=cross_bingo + bingo[width + length*5];
                width++;
                if(cross_bingo==5) bingoCount++;
            }
            cross_bingo = 0;
            for(int length = 0 ; length < 5 ; length++){
                width--;
                cross_bingo=cross_bingo + bingo[width + length*5];
                if(cross_bingo==5) bingoCount++;
            }
            if(bingoCount>=3 && prove==false) {
                prove = true;
                bingo_index = i;
            }
        }
    }
    cout<<bingo_index+1;
    return 0;
}