#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <stack>


using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int number;
    int sum=0;
    cin >> number;
    for(int i = 0 ; i <=6 ; i ++){
        if(number % 2 == 1) sum = sum + 1;
        number = number/2;
        if (number == 0) {
            cout << sum;
            break;
        }
    }

    return 0;
}
