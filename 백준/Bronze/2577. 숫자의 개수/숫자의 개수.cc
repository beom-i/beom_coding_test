#include <iostream>
#include <string>


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a1, a2, a3, sum;
    cin >> a1 >> a2 >> a3;
    sum = a1 * a2 * a3;
    string str = to_string(sum);
    int int_arr[10] = {0};

    for(int i = 0 ; i < str.length() ; i++){
        int a = int(str.at(i) - 48);
        for(int l = 0 ;l < 10;l++){
            if(a == l){
                int_arr[l]++;
            }
        }
    }
    for(int i = 0 ; i < 10 ; i++){
        cout << int_arr[i] << endl;
    }
}
