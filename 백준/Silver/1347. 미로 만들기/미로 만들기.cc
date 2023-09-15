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
    int arr[101][101]={0};
    int direction = 2;

    int N;
    cin >> N;
    string input;
    cin >> input;
    int center_x = 50;
    int center_y = 50;
    
    int max_x=50;
    int min_x=50;
    int max_y=50;
    int min_y=50;
    arr[center_y][center_x]=1;
    for(int i =0 ; i < N;i++){
        if(input[i] == 'R'){
            direction = (direction + 1)%4;
        }
        else if(input[i] == 'L'){
            direction = (direction - 1 )%4;
            if(direction == -1) direction = 3;
        }
        else if(input [i] == 'F'){
            if(direction == 0){
                center_y--;
                if(min_y > center_y) min_y = center_y;
                arr[center_y][center_x] = 1;
            }
            else if(direction==1){
                center_x++;
                if(max_x < center_x) max_x = center_x;
                arr[center_y][center_x] = 1;
            }
            else if (direction == 2){
                center_y++;
                if(max_y < center_y) max_y= center_y;
                arr[center_y][center_x] = 1;
            }
            else if (direction == 3){
                center_x--;
                if(min_x > center_x) min_x = center_x;
                arr[center_y][center_x] = 1;
            }
        }
    }
    for(int i = min_y ; i<=max_y;i++){
        for(int j = min_x;j<=max_x;j++){
            if(arr[i][j] == 1) cout<<".";
            else cout << "#";
        }
        cout <<'\n';
    }
    return 0;
}
