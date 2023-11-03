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

bool compare(string &a, string &b){
    if(a.size() == b.size()) return a<b;
    else return a.size() < b.size();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> v;
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(),v.end(),compare);
    string temp="";
    for(int i = 0 ; i < N ; i++){
        if(temp == v.front()){
            v.erase(v.begin());
            continue;
        }
        temp = v.front();
        v.push_back(v.front());
        v.erase(v.begin());
    }
    for(int i = 0 ; i < v.size() ; i ++){
        cout<<v[i];
        cout<<'\n';
    }
    return 0;
}
