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

int cmp(string a, string b){
    // 길이 다른 경우 
    if(a.size() != b.size()) {
        return a.size() < b.size();
    }
    int asum = 0;
    int bsum = 0;
    for(int i = 0 ; i < a.size();i++){
        int anumber = a[i] -'0';
        int bnumber = b[i] -'0';
        if(anumber >= 0 && anumber <= 9){
            asum = asum + anumber;
        }
        if(bnumber >= 0 && bnumber <= 9){
            bsum = bsum + bnumber;
        }
    }
    if(asum != bsum){
        return asum<bsum;
    }

    for(int i = 0 ; i < a.size();i++){
        if(a[i]!=b[i]){
            return int(a[i]) < int(b[i]);
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<string> str;
    for(int i = 0 ; i < N ; i ++){
        string str1;
        cin >> str1;
        str.push_back(str1);
    }
    sort(str.begin(),str.end(),cmp);
    for(int i = 0 ; i < N ; i ++){
        cout << str[i]<<'\n';
    }
    return 0;
}
