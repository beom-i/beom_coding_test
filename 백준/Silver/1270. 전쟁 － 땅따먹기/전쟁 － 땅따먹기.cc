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
    map<long long,int> m;
    int n; // 땅의 개수
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        int ti; //병사의 개수
        cin >> ti;
        int max_value = 0; // 가장 많이 나온 병사의 수
        long long max_key = 0; //가장 많이 나온 병사의 번호
        for(int i = 0; i < ti; i ++){
            long long ni; // 병사 번호 <= 2^31
            cin >> ni;
            long long tmp = ++m[ni];
            if(tmp > max_value) {max_value = tmp; max_key = ni;}
        } 
        if(max_value > ti/2) cout<< max_key<<"\n";
        else cout<<"SYJKGW\n";
        m.clear();
    }
    return 0;
}
