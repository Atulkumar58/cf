#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, q;
        cin >> n >> q;

        vector<pair<int,int>> a(n), b;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }

        b = a;
        sort(b.begin(), b.end());

        auto ok = [&](int k) {
            DSU dsu(n);

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if ( (i ^ j) <= k )
                        dsu.unite(i, j);
                }
            }

            for (int i = 0; i < n; i++) {
                if (dsu.find(a[i].second) != dsu.find(b[i].second))
                    return false;
            }
            return true;
        };

        int lo = 0, hi = 2 * n, ans = hi;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (ok(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}