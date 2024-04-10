#include <iostream> // For cin, cout, and ios
#include <vector>   // For vector
#include <cstring>  // For memcpy

using namespace std;

int  N,M;
bool isused[10];
int output[10];
void backtracking(int k){
    if(k == M){
        for(int i = 0 ; i < M ; i++){
            cout<<output[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = 1 ; i <= N ; i++){
        if(!isused[i]){
            output[k]=i;
            isused[i]=true;
            backtracking(k+1);
            isused[i]=false;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >>M;
    backtracking(0);
    return 0;
}