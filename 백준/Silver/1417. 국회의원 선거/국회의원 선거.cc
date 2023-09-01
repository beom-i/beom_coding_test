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

    vector<int> vec;
    int N,dasom,pre_money;
    int money=0;
    cin >> N;
    cin >> dasom;
    for(int i = 0 ; i < N-1;i++){
        int human;
        cin>>human;
        // dasom이 더 작을때, human 추가 / 더 크다면 볼 필요 없음
        if(dasom <= human) vec.push_back(human); 
    }
    while(true){
        pre_money = money;
        for(int i=0;i < vec.size() ;i++){
            if(dasom <= vec[i] && vec[i] >= *max_element( vec.begin(), vec.end()) ){
                dasom ++;
                vec[i]--;
                money ++;
                // 추가해두고 다솜이 더 커졌다 그럼 삭제해
                if(dasom>vec[i]){
                    vec.erase(vec.begin()+i);
                }
            }
        }
        if(pre_money == money) break;
    }
    cout << money;
    return 0;
}
