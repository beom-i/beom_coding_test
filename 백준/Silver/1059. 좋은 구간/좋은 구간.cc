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
    int L;
    vector<int> vec;
    cin>>L;
    for(int i = 0 ; i < L ; i ++ ){
        int number;
        cin >> number;
        vec.push_back(number);
    }
    sort(vec.begin(),vec.end());
    int n;
    cin>>n;
    int pre_number=0;
    int cur_number=0;
    for(int i = 0 ; i <vec.size();i++){
        if( n == vec[i]){
            cout<<0;
            return 0;
        };
        if(n < vec[i]){
            cur_number = vec[i];
            break;
        }
        pre_number = vec[i];
    }
    int count=0;
    for(int i = pre_number+1;i<=n;i++){
        for( int l = n;l<cur_number;l++){
            if(i!=l) {
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}
