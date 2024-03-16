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
    string duck;
    getline(cin,duck);
    int count=0;
    int max=0;
    int arr[5]={0};
    for(char c : duck){
        if(c =='q') {arr[0]++;}
        else if(c=='u'){
            arr[1]++;
            if(arr[1] > arr[0]) {cout<<-1;return 0;}
        }
        else if(c=='a'){
            arr[2]++;
            if(arr[2] > arr[0] || arr[2] > arr[1]) {cout<<-1;return 0;}
        }
        else if (c=='c'){
            arr[3]++;
            if(arr[3] > arr[0] || arr[3] > arr[1] || arr[3] > arr[2]) {cout<<-1;return 0;}
        }
        else if(c=='k') {
            arr[4]++;
            if(arr[4] > arr[0] || arr[4] > arr[1] || arr[4] > arr[2] || arr[4] > arr[3]) {cout<<-1;return 0;}
            for(int i = 0 ; i <= 4;i++){
                arr[i]--;
            }
        }
        else{
            cout<<-1;return 0;
        }

        if(arr[0]>=max) max=arr[0];
    }
    for(int i = 0 ; i <= 4;i++){
        if(arr[i]!=0){cout<<-1;return 0;}
    }
    cout<<max;

    return 0;
}