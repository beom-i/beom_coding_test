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
    int prove[27]={0};
    string input;
    getline(cin,input);
    for(int i = 0 ; i < input.length();i++){
        prove[input[i]-'A']++;
    }
    // 가능한지 여부 판단, 홀수 2개 이상이면 I'm Sorry 출력
    int holsu=0;
    for(int i = 0 ; i < 27;i++){
        if(!(prove[i]%2==0)) holsu++;
    }
    if(holsu>1){
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    vector<char> output;
    char lastchar=' ';
    // 가능하다면 팰린드롬 만듬
    for(int i = 0 ; i<26;i++){
        if(prove[i]%2==1) {
            lastchar = i+'A';
            prove[i]--;
        }
        for(int j = 0 ; j<prove[i]/2;j++){
            output.push_back(i+'A');
        }
    }
    if(lastchar != ' '){
        output.push_back(lastchar);
        for(int i = output.size()-2; i >=0;i--){
            output.push_back(output[i]);
        }

        for(int i = 0 ; i < output.size();i++){
            cout << output[i];
        }
    }
    else{
        for(int i = output.size()-1; i >=0;i--){
            output.push_back(output[i]);
        }

        for(int i = 0 ; i < output.size();i++){
            cout << output[i];
        }
    }

    //꺼꾸로 다시 넣음
    return 0;
}
