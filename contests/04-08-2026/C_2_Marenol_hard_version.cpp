#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<int> a_even, a_odd;
    vector<int> b_even, b_odd;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] == '1') a_even.push_back(i);
            if (b[i] == '1') b_even.push_back(i);
        } else {
            if (a[i] == '1') a_odd.push_back(i);
            if (b[i] == '1') b_odd.push_back(i);
        }
    }

    // Check if both strings have matching counts of '1's at even and odd positions
    if (a_even.size() != b_even.size() || a_odd.size() != b_odd.size()) {
        cout << -1 << "\n";
        return;
    }

    long long ops = 0;

    // Calculate ops for even positions
    for (size_t i = 0; i < a_even.size(); i++) {
        ops += abs(a_even[i] - b_even[i]) / 2;
    }

    // Calculate ops for odd positions
    for (size_t i = 0; i < a_odd.size(); i++) {
        ops += abs(a_odd[i] - b_odd[i]) / 2;
    }

    cout << ops << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}