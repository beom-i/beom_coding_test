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

bool vecsum(vector<int>& vec, int value, int max){
    int sum = 0;
    for(int i = 0 ; i < vec.size();i++){
        if(vec[i]>value)sum=sum+value;
        else sum=sum+vec[i];
    }
    if(sum>max) return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int sum = 0;
    int max = 0;
    vector<int> vec;
    for(int i = 0 ; i < N ; i ++){
        int v;
        cin >> v;
        vec.push_back(v);
        sum = sum + v;
        if(max<v){max = v;}
    }

    int M;
    cin >> M;
    // 모든 요청이 배정될 수 없는 경우
    if(sum>M){
        sort(vec.begin(),vec.end());
        //int start=vec.front();int end = vec.back();int mid=vec[vec.size()/2];
        int target = vec[vec.size()-1];
        while(!vecsum(vec,target,M)){
            target--;
        }
        cout<<target;
    }
    // 모든 요청이 배정될 수 있는 경우
    else cout<< max;
}