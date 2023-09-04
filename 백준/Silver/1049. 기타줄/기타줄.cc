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
    int string,brand;
    cin >> string >> brand;
    int six=1000,one=1000;
    for(int i = 0 ; i < brand; i++){
        int six_,one_;
        cin>>six_>>one_;
        if(six>six_) six=six_;
        if(one>one_) one=one_;
    }
    int result1 = string/6 * six + string%6 * one;

    int result2 = (string/6+1) * six;

    if(six>one*6) cout << string*one;
    else if(result1 <= result2) cout<<result1;
    else if(result1>result2) cout << result2;
    return 0;
}