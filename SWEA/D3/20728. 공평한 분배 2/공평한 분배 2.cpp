#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N,K;
        cin>>N>>K;
        vector<int> V;
        for(int i = 0 ; i < N ; i++){
            int n;
            cin >>n;
            V.push_back(n);
        }
        int min = 2147483647;
  
        sort(V.begin(),V.end());
        for(int i = 0 ; i <= N-K;i++){
            int a = V[i+K-1] - V[i];
            if(min>a) min = a;
        }
        cout<<'#'<<test_case<<' ' <<min<<'\n';
	}
    
	return 0;
}