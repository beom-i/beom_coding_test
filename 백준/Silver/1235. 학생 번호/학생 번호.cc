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

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<string> vec;
    for(int i =0;i<N;i++){
        string student;
        cin>> student;
        // 문자열 뒤집음
        reverse(student.begin(),student.end());
        vec.push_back(student);
    }
    int count=1;
    // 중복요소가 없을 때
    while(true){
        set<int> sets;
        for(int i = 0 ; i < vec.size();i++){
            string in = vec[i].substr(0,count);
            sets.insert(stoi(in));
        }
        if(sets.size() == vec.size()) break;
        count++;
    }
    cout<<count;
    return 0;
}