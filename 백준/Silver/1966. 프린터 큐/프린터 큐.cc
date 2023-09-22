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
    int test;
    cin >> test;
    vector<int> vec;
    for(int t =0;t<test;t++){
        // N - 문서의 개수
        // 몇번째 놓인 녀석 찾을 지
        int N,M;
        queue<int> q;
        int priority_count[10]={0};
        int max_priority=0;
        cin >> N >> M;
        int my_index = M;
        for(int i = 0 ; i < N ; i ++) {
            int number;
            cin>>number;
            q.push(number);
            if(max_priority < number) max_priority = number;
            priority_count[number]++;
        }
        int count=1;
        while(true){
            if(q.front()< max_priority){
                if(my_index == 0){
                    my_index = q.size()-1;
                }
                else my_index--;
                q.push(q.front());
                q.pop();
            }
            else{
                if(my_index == 0 ){
                    vec.push_back(count);
                    break;
                }
                else my_index--;
                priority_count[q.front()]--;
                // 제일 큰 수 0되면 다시 초기화해줌
                if(priority_count[q.front()]==0){
                    for(int j=q.front();j>0;j--){
                        if(priority_count[j] !=0) {
                            max_priority=j;
                            break;
                        }

                    }
                }
                q.pop();
                count++;
            }
        }
    }
    for(int i = 0 ; i< test;i++){
        cout<<vec[i]<<'\n';
    }
    return 0;
}
