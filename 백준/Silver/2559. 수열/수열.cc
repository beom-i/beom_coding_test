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
    long N,K;
    cin >> N >> K;
    deque<int> dq;
    long long sum = 0;
    long long max = 0;
    for(int i = 0 ; i <=  N-K ; i ++){
        // 초기 덱 설정
        if(i==0){
            for(int j = 0 ; j < K;j++){
                long long number;
                cin >> number;
                sum = sum + number;
                dq.push_back(number);
            }
            max = sum;
            continue;
        }
        long long number;
        cin>> number;
        sum = sum + dq.front()*-1 + number;
        dq.pop_front();
        dq.push_back(number);
        if (max < sum ) max = sum;
    }
    cout << max;
    return 0;
}
