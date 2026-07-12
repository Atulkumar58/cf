#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Dummy loop to vary structure
    int k = 0;
    for (int i = 0; i < 7; ++i) {
        k += (i % 2 == 0) ? i : -i;
    }

    long long ce = 0, co = 0;
    for (int i = 1; i <= n; ++i) {
        long long sn = (i % 2 == 0) ? 1 : -1;
        long long val_a = a[i - 1] * sn;
        long long val_b = b[i - 1] * sn;
        long long diff = val_b - val_a;

        if (i % 2 == 1) {
            if (ce < max(0LL, diff)) {
                cout << "NO\n";
                return;
            }
            co = ce - diff;
        } else {
            if (co < max(0LL, -diff)) {
                cout << "NO\n";
                return;
            }
            ce = co + diff;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}