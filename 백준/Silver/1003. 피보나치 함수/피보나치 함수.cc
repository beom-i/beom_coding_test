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

int fibonacci(int n, int arr[]) {
    if (n == 0) {
        return arr[0];
    } else if (n == 1) {
        return arr[1];
    } else if (arr[n] == 0) {
        arr[n] = fibonacci(n - 1, arr) + fibonacci(n - 2, arr);
    }
    return arr[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int arr[41] = {0};
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        int sum = fibonacci(n, arr);
        if(n==0) cout << 1 << " " << 0 <<"\n";
        else cout << arr[n-1] << " " << arr[n] << "\n";
    }
    return 0;
}
