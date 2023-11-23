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
    // N < 1,000,000,000 자연수  2 <= L <= 100 자연수
    double N, L;
    cin >> N >> L;

    double X=0;
    int count = -1;
    for(double i = L ; i < 101;i++){
        X = N/i - (i-1)/2;
        if(fmod(X, 1.0) == 0.0 && X>=0 ){
            count = i;
            break;
        }
    }
    if(count == -1) {cout<<-1;return 0;}
    for(int i = X ; i < X+count ;i ++){
        cout << i;
        if(i==X+count-1) break;
        cout << ' ';
    }
    return 0;
}
