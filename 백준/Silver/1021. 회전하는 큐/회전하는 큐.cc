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
    int N,M;
    cin >> N >> M;
    int count=0;
    deque<int> deq;
    vector<int> target_value;
    for(int i = 1 ; i <=N;i++){
        deq.push_back(i);
    }

    for(int i = 0 ; i < M ; i ++){
        int n;
        cin >> n;
        target_value.push_back(n);
    }

    for(int i = 0 ; i < M ; i ++){
        int target = target_value[i];

        int mididx = deq.size()/2;

        int target_index=-1;
        for(int l = 0 ; l < deq.size();l++){                if(deq[l] == target){
            target_index=l;
                break;
            }
        }

        while(true){
            if(deq.front() == target){
                deq.pop_front();
                break;
            }
            if(target_index <= mididx){
                deq.push_back(deq.front());
                deq.pop_front();
                count++;
            }
            else if(target_index > mididx){
                deq.push_front(deq.back());
                deq.pop_back();
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}
