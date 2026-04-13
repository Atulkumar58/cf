#include <iostream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

// Cache queries to stay under the limit
map<vector<int>, int> cache;

int ask(const vector<int>& indices) {
    if (indices.empty()) return 0;
    if (cache.count(indices)) return cache[indices];
    
    cout << "? " << indices.size();
    for (int idx : indices) cout << " " << idx;
    cout << endl;
    
    int res;
    cin >> res;
    if (res == -1) exit(0); // Protocol error
    return cache[indices] = res;
}

int query_prefix(int r) {
    vector<int> v(r);
    iota(v.begin(), v.end(), 1);
    return ask(v);
}

int query_prefix_with_pos3(int r, int pos3) {
    vector<int> v(r);
    iota(v.begin(), v.end(), 1);
    v.push_back(pos3);
    return ask(v);
}

void solve() {
    int n;
    cin >> n;
    int m = 2 * n + 1;
    cache.clear();

    // 1. Find pos3 (the first index where parity breaks)
    int low = 1, high = m, pos3 = m;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (query_prefix(mid) % 2 != mid % 2) {
            pos3 = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // 2. Find pos1 (first index R where adding pos3 doesn't increase count by 1)
    low = 1, high = pos3 - 1;
    int pos1 = pos3 - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (query_prefix_with_pos3(mid, pos3) < query_prefix(mid) + 1) {
            pos1 = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // 3. Find pos2 (first index R where adding pos3 results in no change)
    low = pos1 + 1, high = pos3 - 1;
    int pos2 = pos3 - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (query_prefix_with_pos3(mid, pos3) == query_prefix(mid)) {
            pos2 = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << "! " << pos1 << " " << pos2 << " " << pos3 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}