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

bool descending(int a, int b) {
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int number;
    cin >>number;
    vector<int> vec;

    while (number > 0) {
        int n = number % 10;  // 일의 자리 숫자 추출
        vec.push_back(n);  // char로 변환하여 벡터에 저장
        number /= 10;  // 다음 자리 숫자 추출을 위해 나누기 10
    }
    // 벡터에 한 인덱스마다 저장 완료

    sort(vec.begin(), vec.end(), descending);

    for(int i=0;i<vec.size();i++){
        cout<<vec[i];
    }
    return 0;
}
