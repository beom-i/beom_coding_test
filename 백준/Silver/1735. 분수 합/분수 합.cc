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
#include <iomanip>
#include <set>
#include <map>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a1,a2,b1,b2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    int x = a1*b2 + a2*b1;
    int y = b1*b2;
    int temp_x = a1*b2 + a2*b1;
    int temp_y = b1*b2;
    while(x != 0){
        if(y == 0){
            cout << temp_x / x <<" "<< temp_y / x;
            return 0;
        }
        int temp = y;
        y = x % y;
        x = temp;
    }   
    cout << temp_x <<" "<< temp_y;
    return 0;
}
