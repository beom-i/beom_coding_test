#include <iostream>

using namespace std;


int occur[101] = {0};
int func2(int arr[],int N){
    for(int i = 0 ;i < N;i++){
        if(occur[100-arr[i]] == 1){
            return 1;
        }
        occur[arr[i]] = 1;
    }
    return 0;
}

int main() {
    int arr[] = {1,52,48};
    int a = func2(arr,3);
    cout << a;
    return 0;
}