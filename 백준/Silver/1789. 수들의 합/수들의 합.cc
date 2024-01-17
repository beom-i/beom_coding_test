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

    long long S;
    cin >> S;
    long long sum=0;
    int count=0;
    while(true){
        count++;
        sum = sum + count;
        if(sum > S){
            count --;
            break;
        }
    }
    cout<< count;
}