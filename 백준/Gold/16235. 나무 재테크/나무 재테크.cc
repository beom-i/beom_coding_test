#include <iostream> // For cin, cout, and ios
#include <vector>   // For vector
#include <cstring>  // For memcpy
#include <stdlib.h> // For abs
#include <algorithm>  // For sort


using namespace std;


// 이 문제에서 기억할 것
// 1. 벡터 동적할당 tree.resize(N); for(int i = 0 ; i < N ; i++) tree[i].resize(N);
// 2. 벡터 정렬 sort(arr[i][j].begin(), arr[i][j].end()); -> include algorithm
// 3. 배열 초기화 memset(arr,0,sizeof(arr));
// 4. 반복문 내에서 벡터를 삭제할 때 초기화 되는 것 기억해야함 꼭!!
// 5. 할당하기 전에 그 할당문 사용했는지 실행 순위도 기억해야함

int board[11][11];                 // 현재 양분
int plus_winter[11][11];           // 겨울에 추가되는 양분
vector<vector<vector<int>>> tree;  // 나무 y,x 좌표에 들어있는 나무들의 나이
int between_spring_summer[11][11]; // 봄 ~ 여름 사이 죽어서 추가할 양분

int N,M,K; 
// N (1~10) : 가로 세로 길이
// M (1~N^2): 구매한 나무 개수 
// K (1000) : K 년 후

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,0,1,1,1,0,-1};


void spring(){
    for(int y = 0 ; y < N ; y++){
        for(int x = 0 ; x < N ;x++){
            // 나이 어린애부터 줘야하니까 sort함
            sort(tree[y][x].begin(), tree[y][x].end());

            for(int idx = 0 ; idx < tree[y][x].size() ; idx++){
                int old = tree[y][x][idx];
                // 나이만큼 양분이 있다면
                if(board[y][x] >= old){
                    // 양분을 나이만큼 먹고
                    board[y][x]-=old;
                    // 나이가 1 증가한다.
                    tree[y][x][idx]++;
                }
                // 만약 나이만큼 양분이 없다면
                else{
                    // 해당 나무는 죽는다.
                    tree[y][x].erase(tree[y][x].begin()+idx);
                    idx--;
                    // 그리고 여름에 양분으로 변함
                    between_spring_summer[y][x] += old/2;
                }
            }
        }
    }
}

// 3. 가을에는 나무가 번식 / 번식하는 나무의 나이는 5의 배수
void autumn(int y, int x){
    for(int idx = 0 ; idx < tree[y][x].size() ; idx++){
        int old = tree[y][x][idx];
        // 번식 나무의 나이가 5의 배수이면
        if(old%5 == 0){
            // 주변 8칸을 순회
            for(int dir = 0 ; dir < 8 ; dir ++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                // 범위 밖이면 취소
                if(ny<0||nx<0|| ny>N-1 || nx>N-1) continue;
                // 나이가 1인 나무 추가함
                tree[ny][nx].push_back(1);
            }
        }
    }
} 

void summer(){
    // 죽은 나무의 양분 추가하고 0으로 초기화
    for(int y = 0 ; y < N ; y++){
        for(int x = 0; x < N ;x++){
            board[y][x] += between_spring_summer[y][x];
            autumn(y,x);
            between_spring_summer[y][x]=0;
        }
    }
}
// 4. 겨울에는 양분을 추가한다.
void winter(){
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            board[i][j] += plus_winter[i][j];
        }
    }
}

void seasons(){
    for(int year = 0 ; year < K ;year++){
        spring();
        summer();
        // autumn();
        winter();
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    // 양분 초기화
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j ++){
            int n;
            cin >> n;
            board[i][j] = 5;
            plus_winter[i][j] = n;
        }
    }

    // 벡터 크기 동적 할당
    tree.resize(N);
    for(int i = 0 ; i < N ; i++) tree[i].resize(N);

    // 초기에 심는 나무
    for(int i = 0 ; i < M ; i++){
        int y,x,z;
        cin >> y >> x >> z;
        tree[y-1][x-1].push_back(z);
    }

    // K년 만큼 4 계절 돌리기
    seasons();

    // 살아있는 나무 체크하기 (나이가 0보다 크면 카운트)
    int result=0;
    for(int y = 0 ; y < N ; y++){
        for( int x = 0 ; x < N ; x++){
            for(int idx = 0 ; idx < tree[y][x].size() ; idx++){
                if(tree[y][x][idx] >0) result++;
            }
        }
    }
    cout<<result;
    return 0;
}