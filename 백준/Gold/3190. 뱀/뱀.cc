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
#include <utility>

using namespace std;

// 바라보는 방향 180도 회전
int seeleft(int d){
    if(d==0) return 3;
    else if(d==1) return 0;
    else if(d==2) return 1;
    else return 2;
}
// 바라보는 방향 우측 방향 90도 회전
int seeright(int d){
    if(d==0) return 1;
    else if(d==1) return 2;
    else if(d==2) return 3;
    else return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    // 목표 : 뱀이 나와서 기어다니는데 사과를 먹으면 뱀의 길이가 늘어나고 뱀이 기어다니다가 벽 또는 자신의 몸과 부딪히면 게임 끝

    // 가정 : 몇몇칸에 사과, 보드 끝 칸 벽, 뱀은 맨 위 맨 좌측에서 시작, 오른쪽을 바라봄
    // 규칙 (매 초마다 이동)
    // 1. 뱀은 몸 길이를 늘려 머리를 다음칸에 위치시킨다.
    // 2. 이동한 칸에 사과가 있으면, 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
    // 3. 이동한 칸에 사과가 없다면, 몸 길이를 줄여서 꼬리가 위치한 칸을 비워준다. 몸 길이는 변하지 않음

    // 결과 : 사과의 위치, 뱀 이동경로가 주어질 때 몇초에 게임이 끝나는 지

    int N; // 보드 크기 N 2 ~ 100
    int board[102][102]={0};
    int K; // 사과 개수 K 0 ~ 100
    cin>>N;
    cin>>K;
    
    for(int i = 0 ; i < K ; i ++){
        int y,x;
        cin >> y >> x;
        board[y][x] = 2; // 사과 둠
    }

    //보드 끝에 벽 둠

    int L; // 뱀의 방향 변환 횟수 L 1~100
    cin >> L;
    deque<pair<int,char>> rotate;
    for(int i = 0 ; i < L ; i ++){
        // X초 뒤에 C가 L이면 왼쪽, D이면 오른쪽으로 90도 방향으로 회전 (X : ~ 10000)
        int X; char C;
        cin >> X >> C;
        rotate.push_back({X,C});
    }


    // 뱀 몸 : 1 , 사과 : 2, 벽은 검증으로

    // 뱀의 방향 관련 변수
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    int d = 1; // 초기 뱀 바라보는 방향 : 동쪽

    // 뱀의 몸 좌표 저장 변수
    deque<pair<int,int>> place; 
    place.push_back({1,1});
    int x = place.back().first;
    int y = place.back().second;
    board[y][x] = 1;

    int count = 1;
    while(true){

        int nx = x + dx[d];
        int ny = y + dy[d];

        // 앞으로 가는 쪽에 내 몸이 있거나 벽에 부딪히면 멈춤
        if(board[ny][nx]==1 || (nx < 1 || ny < 1 || nx > N || ny > N)) break;
        // 사과가 있으면 꼬리 그대로 둠
        else if(board[ny][nx] == 2) {
            place.push_back({nx,ny});
            x = nx;
            y = ny;
            board[y][x]=1;
        }
        // 사과가 없으면 꼬리 없앰
        else if(board[ny][nx] == 0){
            board[place.front().second][place.front().first] = 0; 
            place.pop_front();

            place.push_back({nx,ny});
            x = nx;
            y = ny;
            board[y][x]=1;
        }

        // 방향 정보의 해당하면 회전한다.
        if(rotate.front().first == count){
            if(rotate.front().second =='D') {
                d = seeright(d);
                rotate.pop_front();
            }
            else if(rotate.front().second=='L'){
                d = seeleft(d);
                rotate.pop_front();
            }
        }
        count++;
    }
    cout<<count;
    return 0;

}