#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int digits = 0;
    int temp = N;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    // 정수형 배열 할당
    int arr[digits];
    int sor[10] = {};

    for(int i = 0 ; i < digits ; i++){
        arr[i] = N%10;
        sor[arr[i]] = sor[arr[i]] + 1;
        N = N / 10; 
    }

    int sum = sor[6] + sor[9];
    if(sum % 2 == 1){
        sor[6] = sum/2+1;
        sor[9] = sum/2+1;
    }
    else if(sum % 2 == 0){
        sor[6] = sum/2;
        sor[9] = sum/2;
    }

    int storage =0;
    for (int i = 0; i< 10; i++) {
        if( storage < sor[i]){
            storage = sor[i];
        }
    }
    cout << storage;
}
