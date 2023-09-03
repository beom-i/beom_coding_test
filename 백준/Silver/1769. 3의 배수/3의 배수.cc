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
    string N;
    getline(cin,N);
    int count=0;
    bool prove=false;
    int sum=0;
    while(N.length()!=1){
        sum=0;
        for(int i = 0 ; i <N.length();i++){
            sum = sum + (N[i]-'0');
        }
        count++;
        N = to_string(sum);
    }
    sum = N[0]-'0';
    if(sum%3==0) prove=true;
    else prove=false;
    string strprove;
    if(prove) strprove = "YES";
    else if(!prove) strprove = "NO";
    cout<<count<<"\n"<<strprove;

    return 0;
}
