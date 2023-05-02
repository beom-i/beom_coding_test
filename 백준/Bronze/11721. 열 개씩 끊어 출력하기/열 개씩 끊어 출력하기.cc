#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>



using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string in;
    cin >> in;
    int length=in.length();
    int ind=0;
    while(ind<length){
        for(int i = 0 ; i < 10 ; i++){
            cout << in[ind];
            ind++;
            if(ind >= length) break;
        }
        if(ind >= length) break;
        cout << '\n';
    }
    return 0;
}
