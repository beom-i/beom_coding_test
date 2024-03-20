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

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<int> output(N + 1, 0);
    vector<bool> vis(N + 1, false);


    for(int i = 0 ; i < N-1;i++){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    stack<int> S;
    S.push(1);
    vis[1]=true;
    while(!S.empty()){
        int cur = S.top();S.pop();
        for(int c : graph[cur]){
            if(!vis[c]){
                S.push(c);
                vis[c]=true;
                output[c] = cur;
            }
        }
    }
    for(int i = 2 ; i <= N ; i++){
        cout<<output[i]<<'\n';
    }
    return 0;
}


