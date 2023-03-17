#include <iostream>

using namespace std;



int main() {
    int int_arr[26] ={0};
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    for(int i =0 ; i<str.length();i++){
        int stor = (int) str.at(i) - 97;
        int_arr[stor] ++;
    }
    for(int i = 0; i<26;i++){
        cout << int_arr[i] << ' '; 
    }
}
