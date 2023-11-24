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
    // 박성원은 캠프때 쓸 N개의 랜선 만들어야 함
    // 오는 K개의 랜선을 갖고 있음
    // 하지만 K개의 랜선은 길이가 제각각이다.
    // 박성원은 랜선을 N개의 같은 길이 랜선으로 만들고 싶어서 K개의 랜선을 잘라서 만들어야함
    // 자른 랜선 못 붙임

    // 1. 랜선 자르거나 만들 때 손실되는 길이 X
    // 2. K개의 랜선으로 N개 랜선 만들 수 없다.
    // 항상 정수만큼 자른다.
    // 3. N개보다 많이 만드는 것도 N개를 만드는 것에 포함, 최대 랜선의 길이 만드는 프로그램

    // 1 <= K <= 10,000
    // 1 <= N <= 1,000,000
    int K, N;
    cin >> K >> N;

    long long int maxi = 0;
    vector<int> v;
    for(int i = 0 ; i < K ; i ++){
        int lan;
        cin >> lan;
        if(maxi<lan) maxi=lan;
        v.push_back(lan);
    }

    long long start = 1;
    long long end = maxi;
    long long mid;
    long long ans=0;
    while(start<=end){
        long long result=0;
        mid = (start+end)/2;
        for(int i = 0 ; i < K ; i++){
            result = result+(v[i]/mid);
        }
        if(result >= N) {
            if(ans<mid) ans = mid;
            start=mid+1;
        }
        else end=mid-1;
    }
    cout<<ans;
}

