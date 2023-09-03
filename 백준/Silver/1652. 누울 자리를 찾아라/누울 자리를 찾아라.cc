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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[101][101];
    char character;
    int N;
    cin >> N;
    // 벡터에 방을 넣음
    for(int i = 0 ; i <N;i++){
        for(int l = 0 ; l < N ; l ++){
            cin >> character;
            // 아무것도 없다(누울 수 있다.)
            if(character == '.'){
                arr[i][l] = 1;
            }
            // 짐이 있다.
            else if(character == 'X'){
                arr[i][l]=0;
            }
        }
    }
    // 얻은 방을 통해 누울 수 있는 것을 검증
    int gacount=0;
    int secount=0;
    int totalgacount=0;
    int totalsecount=0;
    for(int i = 0 ; i <N;i++){
        for(int l = 0 ; l < N ; l ++){
            if(arr[i][l]==1) gacount++;
            // 중간에 끝나더라도 가로 2개 이상이면 침대 추가
            else if(arr[i][l]==0){
                if(gacount>1){
                    totalgacount++;
                }
                gacount=0;
            }
            // 끝 도달 했을때 가로에 2개 이상이면 침대 추가
            if(l==N-1){
                if(gacount>1){
                    totalgacount++;
                }
                gacount=0;
            }
        }
    }
    for(int i = 0 ; i <N;i++){
        for(int l = 0 ; l < N ; l ++){
            if(arr[l][i]==1) secount++;
            // 중간에 끝나더라도 가로 2개 이상이면 침대 추가
            else if(arr[l][i]==0){
                if(secount>1){
                    totalsecount++;
                }
                secount=0;
            }
            // 끝 도달 했을때 가로에 2개 이상이면 침대 추가
            if(l==N-1){
                if(secount>1){
                    totalsecount++;
                }
                secount=0;
            }
        }
    }
    cout<< totalgacount <<" " << totalsecount;
    return 0;
}
