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
    int Earth,Sun,Moon;
    cin >> Earth >> Sun >> Moon;
    int e=0,s=0,m=0;
    int count = 0;
    while( !(e==Earth && s==Sun && m == Moon)){
        count++;
        e++;
        s++;
        m++;
        if(e==16) e=1;
        if(s==29) s=1;
        if(m==20) m=1;
    }
    cout<<count;
    return 0;
}
