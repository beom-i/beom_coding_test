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

//이 문제를 풀 때, 정렬시키고 높은 값 3개 골라라 인 문제인데
// 문제풀이 답을 보면 arr[i],arr[i+1],arr[i+2]﻿
// 이런식으로 연속해서 3개를 구하더군요. 근데 저는 문제풀 때,
// 1,2,3,4,5,6,7,8 이 있다면 ㅊ
// 총 5가지 경우가 있는데 678말고 578도 해야되는 것 아니냐?
// 라는 생각이 들었는데 생각해보니 삼각형 조건 c가 제일 클 때c<a+b가 되어야하므로 b가 하나 더 작은 것을 굳이 볼 필요는 없구나
// 어차피 최대값이니까 라는 생각이 들었다. 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> vec;
    int N;
    cin >>N;
    for(int i = 0 ; i < N ; i ++){
        int number;
        cin >> number;
        vec.push_back(number);
    }
    sort(vec.begin(),vec.end());
    for(int i = N-1 ; i >= 2 ; i --){
        if(vec[i] < vec[i-1]+vec[i-2]){
            cout << vec[i]+vec[i-1]+vec[i-2];
            return 0;
        }
    }
    cout << -1;
    return 0;
}
