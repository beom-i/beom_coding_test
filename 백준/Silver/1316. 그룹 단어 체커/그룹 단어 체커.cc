#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,pre_idx,idx,count;
    string word;
    cin >>T;
    count = T;
    for(int i = 1 ; i <= T ; i ++){
        bool prove[26]={false};
        cin >> word;
        for(int i = 0 ; i < word.length();i++){
            pre_idx = idx;
            idx = (int) word[i]-97;
            if(prove[idx]==true && pre_idx!=idx){
                count= count-1;
                break;
            }
            prove[idx]=true;
        }
    }
    cout<<count;
    return 0;
}
