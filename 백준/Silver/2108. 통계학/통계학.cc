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
    int N;
    cin >>N;
    int many[8002]={0};
    int max=0;
    int max_index;
    vector<int> vec;
    vector<int> vecvec;
    double sum = 0;
    for(int i = 0;i <N;i++){
        int number;
        cin>>number;
        sum = sum + number;
        vec.push_back(number);

        // 최빈 값
        many[number+4000]++;
        if(max<many[number+4000]) {
            max = many[number+4000];
        }
    }
    // 산술평균
    if(round(sum/N) == -0) cout<<0;
    else cout<<round(sum/N);
    cout  <<'\n';
    // 중앙값
    sort(vec.begin(),vec.end());
    cout<<vec[N/2]<<'\n';

    // 최빈값
    int ccount=0;
    for(int i = 0 ; i <= 8001;i++){
        if(max == many[i]) {
            vecvec.push_back(i-4000);
            ccount++;
        }
    }
    if(ccount>1){
        sort(vecvec.begin(),vecvec.end());
        cout<<vecvec[1]<<'\n';
    }
    else cout<<vecvec[0]<<'\n';

    // 범위
    cout<<vec[N-1] - vec[0]<<'\n';
    return 0;
}
