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

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int A,B;
    cin>>A>>B;
    set<int> set;
    for(int i = 0 ; i < A+B ; i ++){
        int one;
        cin>>one;
        set.insert(one);
    }
    cout<< (A+B)-2*(A+B-set.size());
    return 0;
}