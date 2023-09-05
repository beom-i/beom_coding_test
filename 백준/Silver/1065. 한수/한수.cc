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
#include <iomanip> // std::fixed 및 std::setprecision을 사용하기 위해 필요

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int count=0;
    for(int i = 1 ; i <= N ; i ++){
        int baek,sip,one;
        if(i<100){
            count++;
            continue;
        }
        if(i==1000) continue;
        //백의자리만 생각
        baek = i / 100;
        sip = (i / 10) % 10;
        one = i%10;
        if(baek - sip == sip-one) count++;
    }
    cout<<count;
    return 0;
}