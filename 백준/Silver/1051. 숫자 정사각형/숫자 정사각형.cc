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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin >> N >> M;
    int arr[51][51];
    cin.ignore();
    for(int i = 0 ; i < N ; i ++){
        string input;
        getline(cin,input);
        for(int j = 0 ; j < M ; j ++){
            arr[i][j] = input[j];
        }
    }
    int max = 1;
    int min_ = min(N,M);
    for(int i = 0 ; i < N-1 ; i ++){
        for(int j = 0 ; j < M-1 ; j ++){
            for(int q = 1 ; q < min_ ; q++){
                if(i+q >= N || j+q >= M) break;
                if(arr[i][j] == arr[i+q][j] && arr[i][j+q] == arr[i+q][j+q] && arr[i+q][j] == arr[i][j+q]){
                    if(max<(q+1)*(q+1)) max = (q+1)*(q+1);
                }
            }
        }
    }
    cout<<max;
    return 0;
}