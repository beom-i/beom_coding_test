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
#include <iomanip> // std::fixed 및 std::setprecision을 사용하기 위해 필요
#include <set>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[6][6];
    for(int i = 0 ; i < 6;i++){
        for(int l = 0 ; l < 6 ; l ++){
            arr[i][l] = 1;
        }    
    }
    bool prove=true;
    int x,y;
    int start_x,start_y,end_x,end_y;
    for(int i = 0;i<36;i++){
        string s;
        getline(cin,s);
        // 처음값 저장
        if(i==0){
            start_x = s[0];
            start_y = s[1];
        }
        // 나중값 저장
        if(i==35){
            end_x = s[0];
            end_y = s[1];
        }
        if(i!=0){
            int dx = abs(x-(s[0]-65));
            int dy = abs(y-(s[1]-49));
            if(!((dx == 1 && dy==2) || (dx ==2 && dy==1))) prove=false;
        }
        x = s[0]-65;
        y = s[1]-49;
        if(arr[x][y]==1) arr[x][y]=0;
        else if(arr[x][y] == 0){
            prove=false;
        }
    }
    // 마지막에 돌아갈 수 있는지 판단
    int lastx = abs(start_x-end_x);
    int lasty = abs(start_y-end_y);
    if( !(lastx==1&&lasty==2 || lastx==2 && lasty==1)   ) prove=false;
    if(prove) cout<<"Valid";
    else cout<<"Invalid";
    return 0;
}