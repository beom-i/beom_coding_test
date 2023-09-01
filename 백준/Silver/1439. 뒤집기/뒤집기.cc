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

bool descending(int a, int b) {
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    char number;
    number = str[0];
    int count=0;
    for(int i = 1 ; i <= str.length();i++){
        if(number != str[i]){
            count++;
        }
        number = str[i];
    }
    cout << count/2;
    return 0;
}
