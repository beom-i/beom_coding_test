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

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 사전순 정렬 싫으면 unordered_map<string,int> strings;
    map<string,int> strings;

    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        string str;
        cin >> str;
        int count=0;
        // . 기준으로 문자열 자르기
        for(char c : str){
            if(c=='.'){
                count++;
                str = str.substr(count);
                break;
            }
            count++;
        }
        strings[str]++;
    }

    for(auto it = strings.begin(); it != strings.end(); it++){
        cout<<it->first << " " << it->second << '\n';

    }

    return 0;
}