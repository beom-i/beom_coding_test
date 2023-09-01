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
    int input;
    cin >> input;

    int count = 0;
    int natural=0;

    while(input != count){
        natural++;
        string myString = to_string(natural);
        if(myString.find("666") != string::npos ){
            count++;
        }
    }
    cout<<natural;
    return 0;
}
