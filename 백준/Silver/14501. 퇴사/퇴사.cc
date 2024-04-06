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
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> time;
    vector<int> price;
    int arr[16]={0};

    int N; cin>>N;

    for(int i = 0 ; i < N ; i ++ ){
        int t,p;
        cin >> t >> p;
        time.push_back(t);
        price.push_back(p);
    }

    for(int i = N-1 ; i >=0 ; i--){
        if( i + time[i] > N) continue;
        int more = 0;
        for(int l = i + time[i] ; l < N ; l ++ ){
            if(more < arr[l]) more = arr[l];
        }
        arr[i] = price[i] + more;
    }
    int max = 0;
    for(int i = 0 ; i < N ; i++){
        if(max < arr[i]) max = arr[i];
    }
    cout<<max;
    return 0;

}

