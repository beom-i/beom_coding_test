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

bool yoonyear(int year){
    if(year%400==0) return true;
    if(year%4==0 && year%100!=0) return true;
    return false;
}
int sum_day(string month,int year){
    int sum=0;
    if(month == "January") return sum;
    sum = sum + 31;
    if(month == "February") return sum;
    if(yoonyear(year)){
        sum = sum + 29;
    }
    else if(!yoonyear(year)){
        sum=sum+28;
    }
    if(month == "March") return sum;
    sum=sum+31;
    if(month == "April") return sum;
    sum=sum+30;
    if(month == "May") return sum;
    sum=sum+31;
    if(month == "June") return sum;
    sum=sum+30;
    if(month == "July") return sum;
    sum=sum+31;
    if(month == "August") return sum;
    sum=sum+31;
    if(month == "September")return sum;
    sum=sum+30;
    if(month == "October") return sum;
    sum=sum+31;
    if(month == "November") return sum;
    sum=sum+30;
    if(month == "December") return sum;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ostringstream oss;
    string str;
    int count=0;
    cin>>str;
    for (int i = 0; i < str.length(); i++) {
        if(str[i]=='.'){
            if(!(count%2==0)){
                cout<<-1;
                return 0;
            }
            if(count/4>0){
                oss<<string((count/4)*4,'A');
                count=count-(count/4)*4;
            }
            if(count/2>0){
                oss<<string((count/2)*2,'B');
                count=count-(count/2)*2;
            }
            count=-1;
            oss<<'.';
        }
        count++;
        if(i==str.length()-1){
            if(count%2!=0) {
                cout<<-1;
                return 0;
            }
            if(count/4>0){
                oss<<string((count/4)*4,'A');
                count=count-(count/4)*4;
            }
            if(count/2>0){
                oss<<string((count/2)*2,'B');
                count=count-(count/2)*2;
            }
        }
    }
    cout << oss.str();
    return 0;
}
