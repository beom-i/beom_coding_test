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
    int N;
    cin >> N;
    int arr[5001];
    fill(arr,arr+5001,-1);
    arr[3] = 1;
    arr[5] = 1;
    for(int i = 6 ; i <= N ; i ++){
        if(arr[i-5] != -1){
            arr[i] = arr[i-5]+1;
        }
        else if(arr[i-3] != -1){
            arr[i] = arr[i-3]+1;
        }
        else if(arr[i-3] == -1){arr[i]=-1;}
    }
    cout<<arr[N];
}