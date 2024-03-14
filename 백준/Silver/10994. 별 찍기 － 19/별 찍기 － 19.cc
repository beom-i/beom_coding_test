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
    deque<deque<char>> star;
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        if(i==1){deque<char> row;row.push_back('*');star.push_back(row);continue;}

        // 1. 세로 가운데 줄 먼저 넣음
        for(int a = 1 ; a<=2;a++){
            deque<char> row;
            if(a==2) row.push_back('*');
            else row.push_back(' ');
            star.push_front(row);
        }
        for(int a = 1 ; a<=2;a++){
            deque<char> row;
            if(a==2) row.push_back('*');
            else row.push_back(' ');
            star.push_back(row);
        }
        
        // 2. 반복문 돌면서 양 옆 넣어줄거임
        for(int j = 0 ; j < (i-1)*4+1;j++){
            // stage 1) 처음과 끝
            if(j==0 || j==(i-1)*4){
                for(int b = 1; b <= (i-1)*2;b++){
                    star[j].push_back('*');
                    star[j].push_front('*');
                }
            }
            else if(j==1 || j==(i-1)*4 -1){
                for(int b = 1; b <= (i-1)*2-1;b++){
                    star[j].push_back(' ');
                    star[j].push_front(' ');
                } 
                star[j].push_back('*');
                star[j].push_front('*');
            }
            else{
                star[j].push_back(' ');
                star[j].push_front(' ');  
                star[j].push_back('*');
                star[j].push_front('*');
            }
        }
    }
        // 2중 벡터 출력
    for (const auto& row : star) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << "\n";
    }

    return 0;
}