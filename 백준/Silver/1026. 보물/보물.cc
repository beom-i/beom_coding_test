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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> avec;
    vector<int> bvec;
    for(int i = 0 ; i <N;i++){
        int n;
        cin>>n;
        avec.push_back(n);
    }

    for(int i = 0 ; i <N;i++){
        int n;
        cin>>n;
        bvec.push_back(n);
    }
    sort(avec.begin(),avec.end());
    sort(bvec.begin(),bvec.end(),greater<int>());
    int sum=0;
    for(int i = 0 ; i < N ; i ++){
        sum = sum + avec[i]*bvec[i];
    }
    cout<<sum;
    return 0;
}
