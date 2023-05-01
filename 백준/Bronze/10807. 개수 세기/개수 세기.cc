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
    
    int n,j;
    cin >> n;
    int arr[n];
    for(int i= 0 ; i < n ;i ++){
        cin >> j;
        arr[i] = j;
    }
    int x,sum=0;
    cin >> x;
    for(int i = 0 ; i < n ; i ++){
        if(arr[i] == x) sum++;
    }
    cout << sum;
    return 0;
}
