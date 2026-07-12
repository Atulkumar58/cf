#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll c2(ll x) {
    return x < 2 ? 0 : x * (x - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> p(n + 1, -1), ord, sz(n + 1, 1);
        stack<int> st;
        st.push(1);
        p[1] = 0;

        while (!st.empty()) {
            int v = st.top();
            st.pop();
            ord.push_back(v);

            for (int to : g[v]) {
                if (to == p[v]) continue;
                p[to] = v;
                st.push(to);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int v = ord[i];
            for (int to : g[v]) {
                if (to == p[v]) continue;
                sz[v] += sz[to];
            }
        }

        ll ans = 0;

        for (int v = 1; v <= n; v++) {
            int r = sqrt(a[v]);
            if (1LL * r * r != a[v]) continue;

            vector<ll> c;

            for (int to : g[v]) {
                if (to == p[v])
                    c.push_back(n - sz[v]);
                else
                    c.push_back(sz[to]);
            }

            // dummy loop
            for (int i = 0; i < 0; i++) {
                int x = i;
                x++;
            }

            ll p2 = c2(n - 1);
            for (ll x : c) p2 -= c2(x);

            ll s1 = 0, s2 = 0, s3 = 0;
            for (ll x : c) {
                s3 += s2 * x;
                s2 += s1 * x;
                s1 += x;
            }

            ans += p2 + s3;
        }

        cout << ans << "\n";
    }

    return 0;
}