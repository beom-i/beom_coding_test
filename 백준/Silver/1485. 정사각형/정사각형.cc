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
    int T;
    cin >> T;
    for(int j = 0 ; j < T ; j++){
        vector<pair<double,double>> vec;
        vector<double> distance;

        for(int i = 0 ; i <4;i++){
            double x,y;
            cin >> x >> y;
            vec.push_back({x,y});
        }

        for(int i = 0 ; i <4;i++){
            for(int q = i+1 ; q<4;q++){
                pair<double,double> cur1 = vec[i]; 
                pair<double,double> cur2 = vec[q];
                double x1 = cur1.first;
                double x2 = cur2.first;
                double y1 = cur1.second;
                double y2 = cur2.second;
                double dis = (x2-x1)*(x2-x1) + (y2-y1) * (y2-y1);
                distance.push_back(dis);
            }
        }
        sort(distance.begin(),distance.end());

        if((distance[0]==distance[1] && distance[1]==distance[2] && distance[2] == distance[3]) && (distance[4] == distance[5])&& distance[0]*2 == distance[5]) cout<<1;
        else cout<<0;
        cout<<"\n";
    }
    return 0;
}
