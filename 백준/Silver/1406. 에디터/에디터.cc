#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>



using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string in;
    cin >> in;

    list<char> mylist(in.begin(), in.end()); //문자열 처음과 끝으로 리스트 생성
    list<char>::iterator iter = mylist.end();  //문자열 끝 부분을 iterator로 지정

    int n,temp;

    cin >> n;
    for(int i = 0 ; i <= n;i++){
        string input;
        getline(cin,input);
        if(input[0] == 'L'){
            if(iter!=mylist.begin()) iter--;
        }
        else if(input[0] == 'P'){
            if(iter == mylist.end()) mylist.push_back(input[2]);
            else {
                mylist.insert(iter,input[2]);
            }
        }
        else if(input[0] == 'D'){
            if(iter!=mylist.end()) iter++;
        }
        else if(input[0] == 'B'){
            if(iter == mylist.end()){ 
                mylist.pop_back();
            }
            else if(iter!=mylist.begin()) { 
                iter --; //이게 문제네
                iter = mylist.erase(iter);
            }
        }
    }
    for (auto it = mylist.begin(); it != mylist.end(); it++) {
        cout << *it;
    }
    return 0;
}
