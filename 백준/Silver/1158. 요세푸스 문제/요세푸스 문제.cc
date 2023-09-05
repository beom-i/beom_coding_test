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

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<int> arr;
    vector<int> vec;
    int N,K;
    cin >> N >> K;
    for(int i = 1 ; i <= N;i++){
        arr.push(i);
    }
    while(arr.size()!=0){
        for(int i = 1;i<K;i++){
            arr.push(arr.front());
            arr.pop();
        }
        vec.push_back(arr.front());
        arr.pop();
    }
    cout <<"<";
    for(int i =0;i<vec.size();i++){
        cout<<vec[i];
        if(i==vec.size()-1)break;
        cout<<", ";
    }
    cout<<">";
    return 0;
}