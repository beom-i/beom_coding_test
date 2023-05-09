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
    stack<int> stack;
    int N,num,sum=0;
    cin>>N;
    for(int i = 0 ; i < N ; i ++){
        cin >> num;
        sum = sum + num;
        if(num == 0) {
            sum = sum - stack.top();
            stack.pop();

        }
        else stack.push(num);
    }
    cout << sum;
    return 0;
}
