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

    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N+1);
    vector<int> computer(N+1,0);
    for(int i = 0 ; i < M ; i ++){
        int a,b;
        cin >> a >> b;
        G[b].push_back(a);  // b -> a 해킹 가능 단방향
    }

    int max = 0;
    for(int i = 1 ; i <= N;i++){
        queue<int> Q;
        vector<bool> vis(N+1,false);
        int count = 0;

        Q.push(i);
        vis[i]=true;
        while(!Q.empty()){
            int cur = Q.front();Q.pop();
            computer[i]++;
            count++;
            for(int c : G[cur]){
                if(!vis[c]) {
                    Q.push(c);
                    vis[c] = true;
                }
            }
        }
        if(max<count) max=count;
    }

    for(int i = 1 ; i <=N;i++){
        if(max == computer[i]) cout<<i<<' ';
    }
    return 0;
}


