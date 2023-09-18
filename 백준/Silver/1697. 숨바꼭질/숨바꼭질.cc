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
    int arr[100001];
    fill(arr,arr+100001,-1);
    int subin, young;
    cin >> subin >> young;
    queue<int> Q;
    Q.push(subin);
    arr[subin]=0;
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        int cur_1 = cur - 1;
        int cur_2 = cur + 1;
        int cur_3 = cur * 2;
        if(cur < 0 || cur>100000) continue;
        if( cur_1 >= 0){
            if( arr[cur_1] > arr[cur] + 1 || arr[cur_1] < 0) {
                arr[cur_1] = arr[cur]+1;
                Q.push(cur_1);
            }
        }
        if(cur_2 <= 100000){
            if(arr[cur_2] > arr[cur] + 1 || arr[cur_2] < 0){
                arr[cur_2] = arr[cur]+1;
                Q.push(cur_2);
            }
        }
        if(cur_3 <= 100000){
            if(arr[cur_3] > arr[cur] + 1 || arr[cur_3] < 0){
                arr[cur_3] = arr[cur]+1;
                Q.push(cur_3);
            }
        }
    }
    cout << arr[young];
    return 0;
}
