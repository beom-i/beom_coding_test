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
    cin >> N;
    for(int i =0;i<N;i++){
        int x1,y1,r1,x2,y2,r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double d = sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
        int minus = abs(r1-r2);
        int plus = r1+r2;
        if(d==0 && r1==r2) cout<<-1 << '\n';
        else if(d == minus || d== plus) cout<<1<< '\n';
        else if( minus < d && d < plus) cout<<2<< '\n';
        else cout<<0<< '\n';
    }
    return 0;
}
