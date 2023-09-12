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
    int N;
    cin >> N;
    vector <string> vec;
    int count=1;
    for(int i = 0 ; i < N ; i ++){
        string str;
        cin>>str;

        if(vec.size() == 0){
            vec.push_back(str);
            continue;
        }
        int prove=0;
        for(int j = 0 ; j < vec.size();j++){
            for(int l = 0 ; l <vec[j].length();l++){
                if(str == vec[j]){
                    prove=1;
                    break;
                }
                char firstChar = vec[j][0];
                vec[j].erase(0,1);
                vec[j] = vec[j] + firstChar;
            }
        }
        if(prove == 0) {
            count++;
            vec.push_back(str);
        }
    }
    cout<<count;
    return 0;
}