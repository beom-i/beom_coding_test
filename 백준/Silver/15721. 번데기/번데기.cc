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
    int people, target, guho;
    cin >> people >> target >> guho;
    int sum = 0;
    int answer = 0;
    for(int i = 8; i <20001;i=i+2){
        sum = sum + i;

        if(target<= sum/2 - i/2 +2 ){
            // 왼쪽중에 오른쪽
            if(target == sum/2 -i/2 + 2){
                if(guho==0)answer = (sum - i) + 3;
                else answer = (sum - i) + 4;
                break;
            }
            // 왼쪽중에 왼쪽
            else{
                if(guho==0)answer = (sum - i) + 1;
                else answer = (sum - i) + 2;
                break;
            }
        }
        else if(target <= sum/2){
            if(guho == 0) answer = (sum-i) + 4 + target - ((sum-i)/2+2);
            else answer = (sum-i) + 4 + target - ((sum-i) /2 + 2) + i/2 -2;
            break;
        }
        else continue;
    }
    cout<<(answer-1)%people;
}