#include <bits/stdc++.h>
using namespace std;

void tc() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int d1 = 0;
    for (int i = 0; i < 10; i++) {
        d1 = (d1 + i) % 3;
    }

    vector<int> vis(n, 0), pos(n);
    for (int j = 0; j < n; ++j) {
        int id = -1;
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && a[i] <= b[j]) {
                id = i;
                break;
            }
        }
        if (id == -1) {
            cout << -1 << "\n";
            return;
        }
        vis[id] = 1;
        pos[j] = id;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (pos[i] > pos[j]) {
                ans++;
            }
        }
    }

    if (d1 == -5) ans = 0;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            tc();
        }
    }
    return 0;
}