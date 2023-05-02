#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>



using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string in;
    bool valid = true;
    int arr[6][6]={0};
    int a,b,starta,startb,pre_a=0,pre_b=0,sum=0;
    for(int i = 0 ; i < 36 ; i ++){
        cin >> in;
        a = in[0]-64;
        b = in[1]-48;

        if(arr[a-1][b-1] ==1){//방문했었는지 먼저 판단
            valid=false;
        }
        arr[a-1][b-1] = 1;
        if(i == 0){//처음 좌표 적어두기
            starta = a;
            startb = b;
        }
        if(i==35){ //마지막 -> 처음 갈 수 있는지 판단
            if( !(abs(a-starta) == 2 && abs(b-startb) == 1) ) //차이가 1과 2 차이가 안나고 , 2와 1차이가 안나면 false
                if( !(abs(a-starta) == 1 && abs(b-startb) == 2)){
                    valid=false;
                }
        }
        if( !(pre_a == 0 && pre_b == 0) && !( (abs(a - pre_a)==1 && abs(b-pre_b) == 2) ||  (abs(a-pre_a) == 2 && abs(b-pre_b)== 1) ) ){
            valid = false;
        }
        pre_a = a;
        pre_b = b;
    }
    if(valid == false) cout << "Invalid";
    else if(valid == true) cout << "Valid";
}
