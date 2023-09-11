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
#include <iomanip> // std::fixed 및 std::setprecision을 사용하기 위해 필요
#include <set>
#include <map>
#include <deque>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    vector<int> dilivery;
    vector<int> price;
    cin >> N;
    for(int i= 0 ; i <N;i++){
        int dilivery_;
        int price_;
        cin >> price_ >> dilivery_;
        price.push_back(price_);
        dilivery.push_back(dilivery_);
    }
    int sum = 0;
    int sejun_price=0;
    int max_sejun_price=0;
    int p=0;
    int max_price=0;
    for(int i = 0 ; i < N;i++){
        sejun_price = price[i];
        for(int j = 0 ; j < N ; j ++){
            if(sejun_price>price[j]) continue;
            p = sejun_price - dilivery[j];
            if(p<0) p = 0;
            sum = sum + p;
        }
        if(max_price <= sum) {
            if(max_price == sum){
                if(max_sejun_price>sejun_price) max_sejun_price = sejun_price;
                max_price = sum;
            }
            else{
                max_sejun_price = sejun_price;
                max_price = sum;
            }
        }
        sum=0;
    }
    cout << max_sejun_price;
    return 0;
}