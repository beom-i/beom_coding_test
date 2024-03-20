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

    int subin[100001];
    fill(subin,subin+100001,-1);
    queue<int> Q;
    int N,K;
    cin >> N >> K;
    Q.push(N);
    subin[N] = 0;
    while(!Q.empty()){
        int cur = Q.front();Q.pop();
        if(cur == K) {cout<<subin[cur];return 0;}
        for(int i = 0 ; i < 3 ; i ++){
            int nx;
            if(i==0)  nx = cur -1;
            else if(i==1)  nx = cur + 1;
            else if(i==2)  nx = cur * 2;
            if(nx < 0 || nx > 100000) continue;
            if(subin[nx] != -1) continue;
            subin[nx]=subin[cur]+1;
            Q.push(nx);
        }
    }
    return 0;
}


