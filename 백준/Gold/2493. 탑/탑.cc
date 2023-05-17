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

/*
 * 이 코드를 풀면서 배운 것은 
 * 1) 하나의 풀이에 집착하지 말자.
 * 2) 어떻게 조금이라도 시간을 줄일 것인가 ?  -> 여기서는 다 순회할 필요 없이 과정에 필요없는 것은 과감하게 삭제했다.
 * 3) 어떤 상황에서 조건이 일어나고 어떤 상황에서 종료되고 어떤 상황에 어떤 것을 추가해야할지 확실하게 생각해볼 필요가 있다.
 */
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,count=0;
    cin >> N;
    int height;
    stack<int> stk,idx;
    for(int i = 1 ; i <= N ; i ++){
        cin >> height;
        while(!stk.empty()){
            if(height < stk.top()){
                cout << idx.top() << " ";
                break;
            }
            stk.pop();
            idx.pop();
        }
        if(stk.empty()) cout<<0<<" ";
        stk.push(height);
        idx.push(i);
    }
}
