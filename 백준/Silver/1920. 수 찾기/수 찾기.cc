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
#include <iomanip> // std::fixed 및 std::setprecision을 사용하기 위해 필요
#include <set>
#include <map>
#include <deque>

using namespace std;

bool binarysearch(vector<int> &arr,int target){
    int left = 0;
    int right = arr.size()-1;

    while(left<=right){
        int mid = (left+right)/2;

        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] < target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    vector<int> nvec;
    vector<int> mvec;
    cin >> N;
    for(int i = 0 ; i<N;i++){
        int number;
        cin >> number;
        nvec.push_back(number);
    }
    cin >> M;
    for(int i = 0 ; i<M;i++){
        int number;
        cin >> number;
        mvec.push_back(number);
    }
    sort(nvec.begin(),nvec.end());

    for(int i = 0 ; i < M;i++){
        if(binarysearch(nvec,mvec[i])) cout<<1;
        else cout << 0;
        cout << "\n";
    
    }

    return 0;
}