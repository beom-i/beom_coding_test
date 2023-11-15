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
    
    // 사람들은 자기보다 큰  사람이 왼쪽에 몇명 있었는지를 기억
    // N명의 사람이 있고, 키는 1~N까지 모두 다르다.
    // N은 10보다 작거나 같은 자연수
    // 둘째줄에는 키가 1인 사람부터 차례대로 자기보다 키가 큰 사람이 왼쪽에 몇명 있었는지
    int N;
    cin >> N;
    vector<int> human;
    vector<int> result;
    for(int i = 1 ; i <= N ; i ++){
        int number;
        cin >> number;
        human.push_back(number);
        result.push_back(i);
    }
    int index=0;
    // 1. 맨 뒤부터 자기보다 큰 수의 개수대로 만나면 멈춤
    for(int i = 0 ; i <N ; i ++){
        int count=0;
        if(count == human.back()){
            human.insert(human.begin()+count,human.back());
            result.insert(result.begin()+count,result.back());
            human.erase(human.end()-1);
            result.erase(result.end()-1);
        }
        else{
            for(int l = 0 ; l < N ; l ++){
                if(result[l]>result.back()) count++;
                if(count == human.back()){
                    human.insert(human.begin()+count,human.back());
                    result.insert(result.begin()+count,result.back());
                    human.erase(human.end()-1);
                    result.erase(result.end()-1);
                    break;
                }
            }
        }
    }
    for(int i = 0 ; i < N ; i ++){
        cout << result[i] << ' ';
    }
    return 0;
}
