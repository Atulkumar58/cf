#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Nd {
    ll s;
    int c;
};

vector<Nd> t;
vector<ll> p;

void upd(int u, int l, int r, int x, ll y) {
    t[u].s += y;
    t[u].c++;
    if (l == r) return;
    
    int m = l + (r - l) / 2;
    if (x <= m) upd(2 * u, l, m, x, y);
    else upd(2 * u + 1, m + 1, r, x, y);
}

int qry(int u, int l, int r, ll k) {
    if (k <= 0) return 0;
    if (t[u].s < k) return 1e9;
    if (l == r) {
        ll g = (k + p[l] - 1) / p[l];
        return min((ll)t[u].c, g);
    }
    
    int m = l + (r - l) / 2;
    int rch = 2 * u + 1;
    
    if (t[rch].s >= k) {
        return qry(rch, m + 1, r, k);
    }
    return t[rch].c + qry(2 * u, l, m, k - t[rch].s);
}

void run() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    vector<vector<ll>> g(n, vector<ll>(m));
    p.clear();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            p.push_back(g[i][j]);
        }
    }
    
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    
    int sz = p.size();
    t.assign(4 * sz, {0, 0});
    
    int res = m;
    
    // Dummy loop
    int d_val = 0;
    for (int d = 0; d < 5; d++) {
        d_val = (d_val + d) % 7;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            int pos = lower_bound(p.begin(), p.end(), g[i][j]) - p.begin();
            upd(1, 0, sz - 1, pos, g[i][j]);
        }
        
        int need = qry(1, 0, sz - 1, v[i]);
        res = min(res, need);
    }
    
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    if (cin >> tc) {
        while (tc--) {
            run();
        }
    }
    return 0;
}