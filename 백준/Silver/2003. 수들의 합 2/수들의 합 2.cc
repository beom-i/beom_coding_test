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
    int N, M;
    cin >> N >> M;
    vector<int> v;
    for(int i = 0 ; i < N ; i ++){
        int number;
        cin>>number;
        v.push_back(number);
    }
    int count=0;
    for(int i = 0 ; i < N ; i ++){
        int sum = v[i];
        int idx=1;
        while(true){
            if(sum == M){
                count++;
                break;
            }
            if(i+idx>N) break;
            sum = sum + v[i+idx];
            idx++;
        }
    }
    cout<<count;
    return 0;
}
