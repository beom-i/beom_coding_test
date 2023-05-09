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
    queue<int> q;
    int N,i=0;
    bool tf=true;
    cin >> N;
    for(int z = 0 ; z <  N ; z++){
        int var;
        cin >> var;
        if(i < var){
            for(i = i+1 ; i <= var;i++){
                stack.push(i);
                q.push('+');
            }
            i--;
        }
        else if (i>var){
            if(stack.top() != var){
                tf=false;
            }
        }
        stack.pop();
        q.push('-');
    }

    int size = q.size();
    if(tf){
        for(int l = 0 ; l < size;l++){
            cout << (char)q.front() << '\n';
            q.pop();
        }
    }
    else cout << "NO";
    return 0;
}
