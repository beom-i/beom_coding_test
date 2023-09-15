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
    int N,L;
    cin >> N >> L;
    vector<int> vec;
    for(int i = 0 ; i <  N ; i ++){
        int number;
        cin >> number;
        vec.push_back(number);
    }
    sort(vec.begin(),vec.end());
    int count=1;
    int center=vec[0];
    for(int i = 0 ; i <  N ; i ++){
        if(center-0.5 <= vec[i] && vec[i]<= center+L-0.5){
            continue;
        }
        else{
            count++;
            center = vec[i];
        }
    }
    cout<<count;
    return 0;
}
