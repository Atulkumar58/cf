#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<long long, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }

        sort(a.rbegin(), a.rend());

        vector<long long> res(n + 1);
        res[0] = 0;

        long long ans = 0;
        long long dist = 1;

        for (int i = 0; i < n; i++) {
            long long pos;

            if (i % 2 == 0) {
                pos = dist;        // +1, +2, +3...
            } else {
                pos = -dist;       // -1, -2, -3...
                dist++;
            }

            res[a[i].second] = pos;
            ans += 2LL * a[i].first * abs(pos);
        }

        cout << ans << "\n";
        for (int i = 0; i <= n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}