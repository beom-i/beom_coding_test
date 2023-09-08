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

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    vector<int> vec;
    cin>>N;
    for(int i =0 ; i <N;i++){
        int n;
        cin>>n;
        vec.push_back(n);
    }
    sort(vec.begin(),vec.end());
    int count=0;
    int max=0;
    for(int i = 0 ; i <vec.size();i++){
        for(int l = 1 ;l <  5 ;l++){
            if(vec[i+l]-vec[i]<5 && vec[i+l]-vec[i]>0) count++;
        }
        if(max<count) max=count;
        count=0;
    }
    cout << 4-max;
    return 0;
}