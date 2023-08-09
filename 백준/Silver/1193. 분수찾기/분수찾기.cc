#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int number;
    int n = 1;
    cin>>number;
    while(true){
        if( !((n*n + n)/ 2 < number)){
            break;
        }
        n=n+1;
    }
    int m,result;
    //짝수
    if(n%2 == 0){
        m = n-1;
        result = number - ((m) * (m+1) / 2);
        cout << result << "/" << n+1-result;
    }
    //홀수
    else if(n%2==1){
        m = n-1;
        result = number - ((m) * (m+1) / 2);
        cout << n+1-result << "/" << result;
    }
    return 0;
}
