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
#include <iomanip> // std::fixed 및 std::setprecision을 사용하기 위해 필요
#include <set>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string, int> bookranking;
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        string book;
        cin >> book;
        //데이터가 존재하는지 확인
        if(bookranking.find(book)!=bookranking.end()){
            bookranking[book]++;
        }
        else{
            bookranking.insert({book,1});
        }
    }
    int max=0;
    string max_book;
    for (auto iter : bookranking) {
        if(max<iter.second){
            max=iter.second;
            max_book = iter.first;
        }
    }
    cout<<max_book;
    return 0;
}