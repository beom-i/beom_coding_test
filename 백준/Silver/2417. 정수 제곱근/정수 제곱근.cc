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
    long long N;
    cin >> N;

    long long start,end,mid;
    start = 0; end = pow(2,63)-1;
    while(start<=end){
        mid = (start + end)/2;
        long long sqrtn = sqrt(N);
        if(sqrtn*sqrtn < N) sqrtn= sqrtn+1;
        if( mid == sqrtn) break;
        else if(mid <=sqrtn){start = mid + 1;}
        else end = mid - 1;
    }
    cout<<mid;
}