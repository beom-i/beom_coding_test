#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>


//이 문제는 뭔가 연결리스트의 근본을 알 수있었다. 나는 애초에 stl list에서 추가나 삭제의함수가 실행되었을때
//iterator의 행방이 궁금했다. 배운 점은 이렇고
//1. iterator가 end를 가르키고 있을 때 push_back()하면 iterator은 자동으로 밀림 end로
//2. insert는 iterator의 왼쪽으로 삽입
//3. erase를 하면 반복자를 무조건 재할당 해야됨(iterator = mylist.erase(iterator);)처럼

//이 문제에 관해서는 끝의 경우를 생각하지 않아도 됨 내가 한 이유는 stl list를 충분히 알지 못했다.
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
                iter --;
                iter = mylist.erase(iter);
            }
        }
    }
    for (auto it = mylist.begin(); it != mylist.end(); it++) {
        cout << *it;
    }
    return 0;
}
