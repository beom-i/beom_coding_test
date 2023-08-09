#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <stack>


using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for(int i = 0; i < T ; i ++){
        int N,M;
        long long sum=1;
        cin >> N >> M;
        for(int i = 1 ; i <= N ; i ++){
            sum = sum * (M-N+i) / i;
        }
        cout << sum<<"\n";
    }
    return 0;
}
