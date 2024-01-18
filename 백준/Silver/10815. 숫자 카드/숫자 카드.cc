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
    vector<int> card;
    vector<int> sang;
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        int number;
        cin >> number;
        card.push_back(number);
    }
    cin >> M;
    for(int i = 0 ; i < M ; i ++){
        int number;
        cin >> number;
        sang.push_back(number);
    }

    sort(card.begin(),card.end());

    int start,end;
    for(int i = 0 ; i < sang.size();i++){
        start = 0; end = card.size()-1;
        while(start<=end){
            int mid = (start + end)/2;
            if(card[mid] == sang[i]){cout << "1 ";break;}
            else if(card[mid] > sang[i]){end = mid -1;}
            else {start = mid + 1;}
        }
        if(start>end) cout<< "0 ";
    }
}