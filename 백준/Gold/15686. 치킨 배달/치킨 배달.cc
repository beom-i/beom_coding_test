#include <iostream> // For cin, cout, and ios
#include <vector>   // For vector
#include <cstring>  // For memcpy
#include <stdlib.h> // For abs

using namespace std;

int N,M; // N : 크기 , M : 남겨질 치킨집
int board[52][52];

vector<pair<int,int>> home;
vector<pair<int,int>> chicken;

// i번째집 ~ j번째 치킨집의 거리를 측정
vector<vector<int>> distance_(101);
vector<int> combination;


int result=10000000;

void calculate(){
    int sum = 0;
    for(int i = 0 ; i < home.size();i++){
        int min = 10000000;
        for(int idx : combination){
            if(min > distance_[i][idx-1]) min = distance_[i][idx-1];
        }
        sum+=min;
    }
    if(result > sum ) result = sum;
    return;
}

int visited[14];
// 오픈할 치킨집을 중복해서 뽑음
void combinations(int start, int n, int r) {
    if (r == 0) {
        calculate();
        return;
    }

    for (int i = start; i <= n; ++i) {
        if(visited[i]) continue;
        visited[i]=true;
        combination.push_back(i);
        combinations(i, n, r - 1);  // 조합의 경우 i -> i+1
        visited[i]=false;
        combination.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 도시의 칸 종류
    // 1. 빈 칸
    // 2. 치킨집
    // 3. 집

    // (r,c) r,c 1부터 시작
    // 치킨 거리 : 집 ~ 가장 가까운 치킨집의 거리
    // 도시 치킨 거리 : 각 집의 치킨거리 합
    // r1,c1 ~ r2,c2 거리는 |r1-r2| + |c1-c2| 임

    // 백 트래킹 : 치킨 집 개수 M이 조건

    cin >> N >> M;

    for(int y = 1 ; y <= N ; y ++){
        for(int x = 1 ; x <= N ; x++){
            int n;
            cin >> n;
            board[y][x] = n;
            if(n == 1){home.push_back({y,x});}
            if(n == 2){chicken.push_back({y,x});}
        }
    }

    // i번째집 ~ j번째 치킨집의 거리를 측정
    for(int i = 0 ; i < home.size();i++){
        for(int j = 0 ; j < chicken.size() ; j++){
            int dis = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
            distance_[i].push_back(dis);
        }
    }

    combinations(1,chicken.size(), M);
    cout<<result;
    return 0;
}

// DFS + 백트래킹으로 시도했지만 틀린 코드
// #include <iostream> // For cin, cout, and ios
// #include <vector>   // For vector
// #include <cstring>  // For memcpy
// #include <stdlib.h> // For abs

// using namespace std;

// int N,M; // N : 크기 , M : 남겨질 치킨집
// int board[52][52];

// vector<pair<int,int>> home;
// vector<pair<int,int>> chicken;
// int activated[14]; // 기본값 false;

// int result=1000000000;
// int limit_chicken=0;
// int sum=0;
// void DFS(int count){
//     if(limit_chicken > M) return;
//     // 집 다 돌았으면 마무리
//     if(count == home.size()){
//         if(result>sum) result = sum;
//         return;
//     }

//     for(int i = 0 ; i < chicken.size() ; i++){

//         int dis = abs(home[count].first - chicken[i].first) + abs(home[count].second - chicken[i].second);

//         if(result< sum + dis) continue;

//         if(activated[i] == 0) limit_chicken++;
//         activated[i]++;
//         sum += dis;
//         DFS(count+1);
//         sum -= dis;
//         activated[i]--;
//         if(activated[i] == 0) limit_chicken--;
//     }
//     return;
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     // 도시의 칸 종류
//     // 1. 빈 칸
//     // 2. 치킨집
//     // 3. 집

//     // (r,c) r,c 1부터 시작
//     // 치킨 거리 : 집 ~ 가장 가까운 치킨집의 거리
//     // 도시 치킨 거리 : 각 집의 치킨거리 합
//     // r1,c1 ~ r2,c2 거리는 |r1-r2| + |c1-c2| 임

//     // 백 트래킹 : 치킨 집 개수 M이 조건

//     cin >> N >> M;

//     for(int y = 1 ; y <= N ; y ++){
//         for(int x = 1 ; x <= N ; x++){
//             int n;
//             cin >> n;
//             board[y][x] = n;
//             if(n == 1){home.push_back({y,x});}
//             if(n == 2){chicken.push_back({y,x});}
//         }
//     }

//     DFS(0);
//     cout<<result;
//     return 0;
// }