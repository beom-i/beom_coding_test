#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>



using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N,K,index;
    cin >> N >> K;
    int arr[12]={};
    for(int i = 0 ; i < N ; i++){
        int S,Y;
        cin >> S >> Y;
        if(S == 1){
            index = Y -1;
            arr[index] = arr[index] + 1;
        }
        else if(S==0){
            index = Y+5;
            arr[index] = arr[index] + 1;
        }
    }
    int room = 0;
    for(int i = 0 ; i < 12;i++){
        if(arr[i] % K != 0){
            room = room + 1 +  arr[i]/K;
        }
        else{
            room = room + arr[i]/K;
        }
    }
    cout << room;
    return 0;
}
