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
    long long int X,Y,W,S;
    cin >> X >> Y >> W >> S;
    long long int sum=0;
    if(S<2*W){
        if(W<S){
            sum = min(X,Y)*S+abs(X-Y)*W;
        }
        else if(W>=S){
            sum = sum + min(X,Y)*S+(abs(X-Y)/2)*2*S+(abs(X-Y)%2)*W;
        }
    }
    else sum = (X+Y)*W;
    cout<<sum;
    return 0;
}
