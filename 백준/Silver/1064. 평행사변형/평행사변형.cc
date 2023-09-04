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

using namespace std;

double twodotsub( double x1, double y1, double x2,double y2){
    double X = x2 - x1;
    double Y = y2 - y1;
    double distance = sqrt(X*X + Y*Y);
    return distance;
}
double slope(double x1,double y1,double x2,int y2){
    double slope = abs(y2-y1) / abs(x2-x1);
    return slope;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double xa,ya,xb,yb,xc,yc;
    cin >> xa>>ya>>xb>>yb>>xc>>yc;
    // 예외처리
    if(slope(xa,ya,xb,yb) == slope(xb,yb,xc,yc) && slope(xa,ya,xb,yb) == slope(xa,ya,xc,yc)) {
        cout<<-1.0<<"\n";
        return 0;
    }
    double arr[3];
    arr[0] = twodotsub(xa,ya,xb,yb);
    arr[1] = twodotsub(xb,yb,xc,yc);
    arr[2] = twodotsub(xa,ya,xc,yc);
    sort(arr,arr+3);
    cout.precision(16);
    cout << (2*arr[2]-2*arr[0]);
    return 0;
}