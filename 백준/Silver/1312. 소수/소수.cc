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
    int A,B,N,C,sosu;
    cin >> A>>B>>N;
    A = A%B * 10;
    for(int i = 1 ; i < N ; i ++){
        A = A%B * 10;
    }
    cout<<A/B;
    return 0;
}
