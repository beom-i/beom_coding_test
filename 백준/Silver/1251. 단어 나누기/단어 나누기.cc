#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    vector <string> v;
    cin>>str;
    for(int i = 1 ; i <=str.length()-2 ; i ++){
        for(int l = 1;l<str.length()-i ; l ++){
            string first = str.substr(0,i);
            string second = str.substr(i,l);
            string third = str.substr(i+l);
            reverse(first.begin(),first.end());
            reverse(second.begin(),second.end());
            reverse(third.begin(),third.end());
            v.push_back(first+second+third);
        }
    }
    sort(v.begin(),v.end());
    cout << v.front();
    return 0;
}
