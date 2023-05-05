#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,dasom;
    cin>>N;
    cin>>dasom;
    int arr[50]={};
    int money=0;
    for(int i = 0 ; i<N-1;i++){//dasom이 제외하고 나머지 사람들 투표 저장함.
        cin>>arr[i];
    }
    if(N!=1){
        while(true){
            int max=0,max_idx=0;
            for(int i = 0 ; i <N-1;i++){//다솜이 제외하고 최대표 알아보기
                if(max<arr[i]){
                    max = arr[i];
                    max_idx=i;
                }
            }
            if(max < dasom){//다솜이보다 콘 녀석이 없으면 끝냄
                cout << money;
                break;
            }
            //다솜이보다 큰 녀석이 있으면 -> 그녀석 줄이고 다솜이 늘리고 쓴 돈 증가시킴
            arr[max_idx]--;
            dasom++;
            money++;
        }
    }
    else cout<<money;
    return 0;
}