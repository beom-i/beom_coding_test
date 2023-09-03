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
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string entire,part;
    getline(cin,entire);
    getline(cin,part);
    int count=0;
    while(!(entire.find(part)==-1)){
        int idx = entire.find(part);
        entire.replace(idx,part.length(),"1");
        count++;
    }
    cout << count;
    return 0;
}
