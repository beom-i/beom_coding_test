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
    string month,day,year,hour,minute;
    int iyear,sum,iday,ihour,iminute=0 ;
    double sum_minute=0;
    int entire = 365;
    getline(cin,month,' ');
    getline(cin,day,' ');
    getline(cin,year,' ');
    getline(cin,hour,':');
    getline(cin,minute);
    day.pop_back();
    iyear = stoi(year);
    iday = stoi(day);
    ihour = stoi(hour);
    iminute = stoi(minute);
    sum = sum_day(month,iyear);
    sum = sum + iday-1;
    // 윤년이면 총 366일
    if(yoonyear(iyear)) entire = entire+1;
    entire = entire*1440;
    sum_minute = sum * 1440 + (double)ihour * 60 + iminute;
    
	double calc = sum_minute / entire * 100; // 진행율 계산
	std::cout.precision(9); // 소수점 9자리로 고정
	std::cout << std::fixed;
	std::cout << calc << std::endl;
    return 0;
}
