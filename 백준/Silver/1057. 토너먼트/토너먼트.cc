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
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,jimin,hansu;
    cin >> N >> jimin >> hansu;
    int count=0;
    // 부전승 처리
    while(N/2!=0){
        if(N%2!=0) N++;
        count++;
        if(jimin%2!=0) jimin++;
        if(hansu%2!=0) hansu++;
        if(jimin-hansu==1 || hansu-jimin==1 || hansu == jimin){
            break;
        }
        jimin = jimin/2;
        hansu = hansu/2;
        N = N/2;
    }
    cout<<count;
    return 0;
}