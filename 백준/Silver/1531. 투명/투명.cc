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
    int N,M;
    cin>> N >> M;
	int arr[101][101] = { 0, };
    for(int i = 0 ; i < N ; i ++ ){
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        for(int i = lx;i<=rx;i++){
            for(int l = ly; l<=ry; l++){
                arr[i][l]++;
            }
        }
    }
    int count = 0 ; 
    for(int i = 1 ; i <101;i++){
        for(int l = 1 ; l < 101 ; l ++){
            if(arr[i][l]>M) count++;
        }
    }
    cout<<count;
    return 0;
}
