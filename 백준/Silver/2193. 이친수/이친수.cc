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
    // 1 1 2 3 5 8
    int N;
    cin>>N;
    long long arr[92]={0};
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3 ; i <= N;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout<<arr[N];
    return 0;
}
