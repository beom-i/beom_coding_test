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
    // 1. 1000000 배열 생성
    // 2. 2 ~ N 까지 배수 삭제 (N까지만)
    // 3. N ~ M 출력
    bool arr[1000002]={false};
    arr[1] = true;
    int m,n;
    cin >> m >> n;
    for(int i = 2;i<=n;i++){
        int tmp = i;
        int cnt = 2;
        while(tmp*cnt<=n){
            arr[tmp*cnt] = true;
            cnt++;
        }
    }
    for(int i = m ; i <= n ;i++){
        if(!arr[i]) cout << i << '\n';
    }
    return 0;
}
