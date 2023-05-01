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
    
    string str1,str2;
    int N;
    cin >> N;
    for(int i = 0 ; i < N;i++){
        cin >> str1 >> str2;
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        if(str1==str2){
            cout << "Possible" << "\n";
        }
        else{
            cout << "Impossible" << "\n";
        }
    }
    return 0;
}
