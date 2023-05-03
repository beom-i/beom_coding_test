#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    list<int> array;  
    int N,K,sum=0;
    cin >> N >> K;
    for(int i = 1 ; i<= N;i++){
        array.push_back(i);
    }
    cout << "<";
    list<int>::iterator iter = array.begin(); 
    int count = 1;
    while(!array.empty()){
        if(iter == array.end()){
            iter = array.begin();
        }
        if(count == K){
            cout<<*iter;
            iter = array.erase(iter);
            count=1;
            if(K == 1){
                count --;
            }
            if(array.empty()) break;

            cout << ", ";

        }
        if(iter != array.end()) {
            count++;
            iter++;
            if(K==1) iter --;
        }
    }
    cout << ">";
    return 0;
}