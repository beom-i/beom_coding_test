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
    int switch_count;
    cin>>switch_count;
    vector<bool> vec;
    for(int i = 0 ; i < switch_count ; i++){
        int n;
        cin>>n;
        vec.push_back(n);
    }

    int student_count;
    cin >> student_count;
    for(int i = 0 ; i < student_count;i++){
        int sex,swi;
        cin>>sex>>swi;
        // 남자의 경우 : 배수 스위치 킴/끔
        if(sex == 1){
            for(int l = 1 ; l*swi <= switch_count ;l++){
                vec[l*swi-1] = !vec[l*swi-1];
            }
            continue;
        }
        // 여자의 경우 : 자신의 인근 녀석이 같으면 계속 넘어감.
        else if(sex == 2){
            swi=swi-1;
            int count = 0;
            while( swi-count >=0 && swi+count < switch_count){
                int x = swi-count;
                int y = swi+count;
                if(vec[x] == vec[y]){
                    if(x==y) vec[x] = !vec[x];
                    vec[x] = !vec[x];
                    vec[y] = !vec[y];
                }
                else break;
                count++;
            }
            continue;
        }
    }
    // 틀린 이유 1 : 처음과 끝 생각 못함
    // 틀린 이유 2 : 문제에 출력형식 확인 못해서 계속 틀렸음
    for(int i = 0 ; i < switch_count ; i++){
        if(i!=0 && i%20==0)cout<<'\n';
        cout<<vec[i]<< " ";
    }
    return 0;
}