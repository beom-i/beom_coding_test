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
    string str1,str2;
    cin >> str1;
    cin >> str2;
    int arr1[26]={};
    int arr2[26]={};
    for(int i = 0 ; i< str1.length() ; i ++){
        int index = int(str1[i]) - 97;
        arr1[index] = arr1[index] + 1;
    }

    for(int i = 0 ; i< str2.length() ; i ++){
        int index = int(str2[i]) - 97;
        arr2[index] = arr2[index] + 1;

    }
    
    int sum = 0;
    for(int i = 0 ; i < 26 ; i ++){
        if(arr1[i] > arr2[i]){
            sum = sum + arr1[i] - arr2[i];
        }
        else if(arr1[i] < arr2[i]){
            sum = sum + arr2[i] - arr1[i];
        }
    }
    cout << sum;
    return 0;
}
