#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, T;
    cin >> N >> T;
    set<int> bus_times;

    for (int i = 0; i < N; i++) {
        int start, interval, count;
        cin >> start >> interval >> count;
        
        for (int j = 0; j < count; j++) {
            int time = start + j * interval;
            bus_times.insert(time);
        }
    }

    if (bus_times.empty()) {
        cout << -1 << endl;
    } else {
        if (bus_times.count(T) > 0) {
            cout << 0 << endl;
        } else {
            auto next_bus = bus_times.upper_bound(T);
            if (next_bus == bus_times.end()) {
                cout << -1 << endl;
            } else {
                cout << *next_bus - T << endl;
            }
        }
    }

    return 0;
}
