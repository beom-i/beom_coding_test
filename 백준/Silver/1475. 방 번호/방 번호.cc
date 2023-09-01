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
    int arr[10]={0};
    string str;
    cin>>str;
    int max=0;
    for(int i = 0 ; i<str.length();i++){
        int n = str[i] -'0';
        arr[n] = arr[n] + 1;
    }

    //6과 9의 예외처리
    int sum=0;
    if((arr[6]+arr[9])%2==0) sum = (arr[6]+arr[9])/2;
    else sum = (arr[6]+arr[9])/2+1;
    arr[6] = sum;
    arr[9] = sum;
    for(int i = 0 ; i < 10;i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    cout<<max;
    return 0;
}
