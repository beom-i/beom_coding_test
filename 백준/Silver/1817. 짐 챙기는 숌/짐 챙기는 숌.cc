#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int book_count,box_kg;
    cin >> book_count>>box_kg;
    stack<int> stack;
    for(int i = 0 ; i < book_count;i++){
        int book;
        cin >> book;
        stack.push(book);
    }

    int count=0;
    int temp=box_kg;
    while(stack.size() !=0){
        if(stack.top()<=temp){
            if(count==0) count=1;
            temp = temp - stack.top();
            stack.pop();
        }
        else{
            count++;
            temp = box_kg;
        }
    }
    cout<<count;
    return 0;
}
