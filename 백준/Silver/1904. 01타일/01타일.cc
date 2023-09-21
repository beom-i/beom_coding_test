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
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    int N;
    cin >> N;
    int i = 2;
    if(N>=2){
        while(i != N){
            vec.push_back( (vec[i-2] + vec[i-1]) % 15746);
            i++;
        }
        N=i-1;
    }
    else if (N==1){
        cout<<1;
        return 0;
    }
    cout<< vec[N];
    return 0;
}
