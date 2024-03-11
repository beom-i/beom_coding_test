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
    // 1. 전체 돈
    int money;
    cin >> money;
    int jun = money; int sung = money;
    int jun_count =0; int sung_count=0;
    int change=0;
    // 2. 14일간 주가 저장
    int stk_price,prev_stk_price;
    for(int i = 0 ; i < 14;i++){
        cin >>stk_price;
        // 준현
        if(jun != 0 && jun>=stk_price) {
            jun_count = jun_count+jun/stk_price;
            jun = jun - (jun/stk_price) * stk_price;
        }
        // 성민
        if(i != 0) {
            if(stk_price > prev_stk_price ){ // 증가
                if(change < 0) {change = 0; change++;}
                else change++;

                if(change > 2 && sung_count>0 ){ // 매도 과정
                    sung = sung + sung_count * stk_price;
                    sung_count=0;
                }
            }
            else if(stk_price < prev_stk_price ){ // 감소
                if(change >0 ) {change=0;change--;}
                else change--;

                if(change < -2 && sung > stk_price ){ // 매수 과정
                    sung_count = sung_count + sung / stk_price;
                    sung = sung - (sung / stk_price) * stk_price;
                }
            }
            else{change=0;}
        }

        prev_stk_price = stk_price;
    }

    if(jun + jun_count*stk_price < sung + sung_count*stk_price)cout<<"TIMING";
    else if(jun + jun_count*stk_price > sung + sung_count*stk_price) cout<<"BNP";
    else cout<<"SAMESAME";
    return 0;
}