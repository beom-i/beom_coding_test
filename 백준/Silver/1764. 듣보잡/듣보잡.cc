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


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin >> N >> M;
    vector<string> vec;
    vector<string> output;
    for(int i = 0 ; i < N+M;i++){
        string str;
        cin >> str;
        vec.push_back(str);
    }
    sort(vec.begin(),vec.end());
    for(int i = 0 ; i < vec.size()-1;i++){
        if(vec[i] == vec[i+1]){
            output.push_back(vec[i]);
        }
    }
    cout << output.size()<<endl;
    for(int i = 0 ; i < output.size();i++){
        cout<< output[i]<<endl;
    }
    return 0;
}