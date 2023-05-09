#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int* arr = (int*)malloc(sizeof(int) * N); //동적할당
    for (int i = 0 ; i < N ; i ++){
        cin >> arr[i];
    }
    sort(arr,arr+N);
    int sum=0,start=0,end=N-1;
    int goal,count =0;
    cin >> goal;
    while(start < end){
        sum = arr[start] + arr[end];
        if(sum == goal){
            count ++;
            start++;
            end--;
        }
        else if(sum < goal){
            start++;
        }
        else if(sum>goal){
            end--;
        }
    }
    cout << count;
    return 0;
}
