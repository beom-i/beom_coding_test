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

vector<vector<int>> G(1001);
vector<int> bfs_order;
vector<int> dfs_order;
bool vis[1001];

void dfs(int V){
    vis[V] = true;
    dfs_order.push_back(V);
    for(auto nxt : G[V]){
        if(!vis[nxt]){
            vis[nxt]=true;
            dfs(nxt);
        }
    }
}

void bfs(int V){
    queue<int> Q;
    vis[V]=true;
    Q.push(V);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        bfs_order.push_back(cur);
        for(auto nxt : G[cur]){
            if(!vis[nxt]){
                Q.push(nxt);
                vis[nxt] =true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 1. visit 변수명 사용하지 않기
    // 2. memset은 -1,0 아니면 사용 ㄴㄴ Fill로 배열이나 벡터 초기화하자
    // 3. 채우는 bfs,dfs 아니라 그래프 간선 dfs - 재귀 / bfs - 큐 
    // 4. vector<vector<int>> G(1001); 이렇게 벡터도 배열처럼 쓸 수 있다!
    int N,M,V;
    cin >> N >> M >> V;
    for(int i = 0 ; i <M;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1 ; i <=N ; i ++) sort(G[i].begin(),G[i].end());
    memset(vis, false, sizeof(vis));
    dfs(V);
    memset(vis, false, sizeof(vis));
    bfs(V);
    for(int n : dfs_order){
        cout<<n<<' ';
    }
    cout<<'\n';
    for(int n : bfs_order){
        cout<<n<<" ";
    }
    cout<<'\n';
    return 0;
}


