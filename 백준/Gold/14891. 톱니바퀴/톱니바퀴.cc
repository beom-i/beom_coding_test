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



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    // 회전시킬 톱니바퀴와 회전시킬 방향을 결정
    // 1. A가 회전할 때 B 극이 다르면, B는 A가 회전한 방향과 반대 방향으로 회전한다.
    // 2. A가 회전할 때 B 극이 같으면, B는 회전하지 않는다.

    // 입력 : 8개의 정수로, 12시방향부터 시계방향으로 N극은 0, S극은 1로 나타냄
    int K; // 회전 횟수 1 ~ 100 (회전시킬 톱니바퀴 번호, 방향-1이면 시계, -1 반시계)

    vector<string> S;

    for(int i = 0 ; i < 4 ; i ++){
        string s;
        getline(cin,s);
        S.push_back(s);
    }

    int east[4]={2,2,2,2};
    int west[4]={6,6,6,6};

    int dir[4]={0,0,0,0};

    cin>>K;
    for(int i = 0 ; i < K ; i++){
        int number,di;
        cin>>number>>di;
        if(number==1){
            dir[0]=di;
            for(int j = 0 ; j < 3 ; j ++){
                if(dir[j]==0) {dir[j+1]=0;continue;}

                if(S[j][east[j]]==S[j+1][west[j+1]]) dir[j+1]=0;
                else if(S[j][east[j]]!=S[j+1][west[j+1]]) dir[j+1]=dir[j]*-1;
            }
        }
        else if(number == 2){
            dir[1]=di;
            if(S[0][east[0]] == S[1][west[1]]) dir[0]=0;
            else if(S[0][east[0]] != S[1][west[1]]) dir[0] = dir[1]*-1;

            if(S[1][east[1]] == S[2][west[2]]) {
                dir[2]=0;
                dir[3]=0;
            }
            else if(S[1][east[1]] != S[2][west[2]]){
                dir[2] = dir[1]*-1;
                if(S[2][east[2]]==S[3][west[3]]) dir[3]=0;
                else if(S[2][east[2]] != S[3][west[3]]) dir[3]=dir[2]*-1;
            } 
        }
        else if(number==3){
            dir[2]=di;
            if(S[2][east[2]] == S[3][west[3]]) dir[3]=0;
            else if(S[2][east[2]] != S[3][west[3]]) dir[3] = dir[2]*-1;

            if(S[1][east[1]] == S[2][west[2]]) {
                dir[1]=0;
                dir[0]=0;
            }
            else if(S[1][east[1]] != S[2][west[2]]){
                dir[1] = dir[2]*-1;
                if(S[0][east[0]] ==S[1][west[1]]) dir[0]=0;
                else if(S[0][east[0]] != S[1][west[1]]) dir[0]=dir[1]*-1;
            } 
        }
        else if(number==4){
            dir[3]=di;
            for(int j = 2 ; j >=0 ; j --){
                if(dir[j+1]==0) {dir[j]=0;continue;}

                if(S[j][east[j]]==S[j+1][west[j+1]]) dir[j]=0;
                else if(S[j][east[j]]!=S[j+1][west[j+1]]) dir[j]=dir[j+1]*-1;
            }
        }

        for(int j=0;j<4;j++){
            east[j] = (east[j] + dir[j]*-1 + 104)%8;
            west[j] = (west[j] + dir[j]*-1 + 104)%8;
        }
    }
    int sum=0;
    if(S[0][(east[0]-2+104)%8]=='1') sum+=1;
    if(S[1][(east[1]-2+104)%8]=='1') sum+=2;
    if(S[2][(east[2]-2+104)%8]=='1') sum+=4;
    if(S[3][(east[3]-2+104)%8]=='1') sum+=8;

    cout<<sum;
    return 0;
}