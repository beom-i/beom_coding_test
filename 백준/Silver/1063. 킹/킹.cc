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

void move_chess(int* x, int*y,string move){
    if(move=="R") (*x)++;
    else if(move =="L") (*x)--;
    else if(move == "B") (*y)--;
    else if(move == "T") (*y)++;
    else if(move == "RT"){
        (*x)++;
        (*y)++;
    }
    else if(move == "LT"){
        (*x)--;
        (*y)++;
    }
    else if(move == "RB"){
        (*x)++;
        (*y)--;
    }
    else if(move == "LB"){
        (*x)--;
        (*y)--;
    }
}
void chess(int* king_x,int* king_y,int* stone_x,int* stone_y,string move){
    int pre_king_x=*king_x;
    int pre_king_y=*king_y;
    int pre_stone_x=*stone_x;
    int pre_stone_y=*stone_y;
    // 이미 king_x에서 주소를 받아왔기 때문에 굳이 &안해도됨

    move_chess(king_x,king_y,move);

    // 만약 범위에 존재하지 않는다면,
    if(!((*king_x>=0 && *king_x<=7) && (*king_y>=0 && *king_y <=7)) ){
        *king_x = pre_king_x;
        *king_y = pre_king_y;
    }

    // 돌과 왕이 만났을 때
    if(*king_x == *stone_x && *king_y == *stone_y){
        move_chess(stone_x,stone_y,move);
    }

    if(!((*stone_x>=0 && *stone_x<=7) && (*stone_y>=0 && *stone_y <=7)) ){
        *king_x = pre_king_x;
        *king_y = pre_king_y;
        *stone_x = pre_stone_x;
        *stone_y = pre_stone_y;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int arr[9][9];

    string king_idx,stone_idx;

    int N;

    // 초기 돌과 왕의 위치를 정수로 바꿈
    cin >> king_idx >> stone_idx >> N;

    int king_x = king_idx[0] -'A';
    int king_y = king_idx[1] -'1';
    int stone_x = stone_idx[0] -'A';
    int stone_y = stone_idx[1] -'1';

    for(int i = 0 ; i < N ; i ++){
        string move;
        cin >> move;
        chess(&king_x,&king_y,&stone_x,&stone_y,move);
    }
    char a = king_x+'A';
    char b = stone_x+'A';
    cout << a << king_y+1<<'\n';
    cout << b << stone_y+1;
    return 0;
}
