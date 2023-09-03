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
using namespace std;

void array_up_dw(char arr[][11],int se, int ga){
    if(arr[se][ga] == '.' ){
        arr[se][ga] = '|';
    }
    else if(arr[se][ga]=='-'){
        arr[se][ga] = '+';
    }
}

void array_le_ri(char arr[][11],int se, int ga){
    if(arr[se][ga] == '.' ){
        arr[se][ga] = '-';
    }
    else if(arr[se][ga]=='|'){
        arr[se][ga] = '+';
    }
}
int exception_(int &se,int &ga,int &N,int &prove){
    if(ga<0||se<0||ga>N-1||se>N-1){
        if(ga<0) ga=0;
        if(se<0) se=0;
        if(ga>N-1) ga=N-1;
        if(se>N-1) se=N-1;
        prove = 0;
        return 0;
    }
    prove = 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char arr[11][11];
    string str;
    getline(cin,str);
    int N = stoi(str);
    //기본 값 세팅
    for(int i = 0 ; i <N;i++){
        for(int l = 0 ; l < N ; l ++){
            arr[i][l]='.';
        }
    }
    string input;
    getline(cin,input);
    int ga=0,se=0;
    for(int i = 0 ; i <input.length();i++){
        int prove=1;
        // 범위 밖이면 행동하지 않음
        // 실제 로봇의 동작
        if(input[i] == 'U'){
            se--;
            exception_(se,ga,N,prove);
            if(prove==0) {
                continue;
            }
            se++;
            array_up_dw(arr,se,ga);
            se--;
            array_up_dw(arr,se,ga);
        }
        else if(input[i] == 'D'){
            se++;
            exception_(se,ga,N,prove);
            if(prove==0) {
                continue;
            }
            se--;
            array_up_dw(arr,se,ga);
            se++;
            array_up_dw(arr,se,ga);
        }
        else if(input[i] == 'L'){
            ga--;
            exception_(se,ga,N,prove);
            if(prove==0) {
                continue;
            }
            ga++;
            array_le_ri(arr,se,ga);
            ga--;
            array_le_ri(arr,se,ga);
        }
        else if(input[i] =='R'){
            ga++;
            exception_(se,ga,N,prove);
            if(prove==0) {
                continue;
            }
            ga--;
            array_le_ri(arr,se,ga);
            ga++;
            array_le_ri(arr,se,ga);
        }
    }

    // 출력
    for(int i = 0 ; i <N;i++){
        for(int l = 0 ; l < N ; l++){
            cout<<arr[i][l];
        }
        cout<<"\n";
    }
    return 0;
}
