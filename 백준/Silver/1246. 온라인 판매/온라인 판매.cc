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
    int N,M;
    cin>>N>>M;
    vector<int> vec;
    for(int i = 0 ; i < M ; i ++){
        int pi;
        cin>>pi;
        vec.push_back(pi);
    }
    sort(vec.begin(),vec.end());
    int sum=0;
    int max=0;
    int price=0;
    for(int i = 0 ; i < vec.size();i++){
        if(vec.size()-i>=N) sum = vec[i]*N;
        else sum = vec[i]*(vec.size()-i);
        if(max<sum) {
            price = vec[i];
            max= sum;
        }
    }
    cout<<price<<" "<<max;
    return 0;
}