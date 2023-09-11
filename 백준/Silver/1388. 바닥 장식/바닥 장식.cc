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
#include <deque>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin >> N >>M;
    int arr[51][51]={0};
    // - 이면 1 , | 이면 0
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < M ; j ++){
            char c;
            cin >> c;
            if(c=='-') arr[i][j] = 1;
            else arr[i][j] = 2;
        }
    }
    int count=0;
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < M ; j ++){
            if(arr[i][j] == 1) {
                count++;
                if(arr[i][j] == arr[i][j+1]) count--;
            }
        }
    }

    for(int i = 0 ; i < M ; i ++){
        for(int j = 0 ; j < N ; j ++){
            if(arr[j][i] == 2){
                count++;
                if(arr[j][i] == arr[j+1][i]) count--;
            }
        }
    }
    cout<<count;
    return 0;
}