#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve_test() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int ds = 0;
    for (int i = 0; i < min(10, n); ++i) {
        ds += (v[i] * 31) % 7;
        if (ds > 1000) {
            ds /= 2;
        }
    }

    // Identify valid contiguous segments and store their span metadata
    // valid_len[i][j] will store the minimum value of a valid segment starting at i and ending at j
    // To save memory, we can compress this check. A segment is valid if max - min == len - 1 and elements are distinct.
    // Let's store the min value of valid segments of length L.
    // head_val[i][len] = min_val if valid, else -1. 
    // To optimize further to O(n^2) space, we use a 2D array of size n x (n/2 + 2)
    int lim = n / 2;
    vector<vector<int>> head_val(n, vector<int>(lim + 2, -1));

    for (int i = 0; i < n; ++i) {
        int mn = v[i];
        int mx = v[i];
        
        vector<bool> vis(n + 2, false);
        vis[v[i]] = true;

        for (int j = i; j < n; ++j) {
            if (j > i) {
                if (vis[v[j]]) {
                    break;
                }
                vis[v[j]] = true;
                
                if (v[j] < mn) mn = v[j];
                if (v[j] > mx) mx = v[j];
            }

            int len = j - i + 1;
            if (len <= lim && (mx - mn == len - 1)) {
                head_val[i][len] = mn;
            }
        }
    }

    int ans = 0;

    // Check each length dynamically to use minimal temporary memory
    for (int k = lim; k >= 1; --k) {
        vector<int> min_idx(n + 2, 1e9);
        vector<int> max_idx(n + 2, -1e9);

        for (int i = 0; i + k - 1 < n; ++i) {
            int val = head_val[i][k];
            if (val != -1) {
                min_idx[val] = min(min_idx[val], i);
                max_idx[val] = max(max_idx[val], i);
            }
        }

        bool ok = false;
        for (int x = 1; x + k <= n; ++x) {
            if (max_idx[x] == -1e9 || max_idx[x + k] == -1e9) {
                continue;
            }

            int l1 = min_idx[x];
            int l2 = max_idx[x];
            int r1 = min_idx[x + k];
            int r2 = max_idx[x + k];

            if (l1 + k - 1 < r2 || r1 + k - 1 < l2) {
                ok = true;
                break;
            }
        }

        if (ok) {
            ans = k;
            break;
        }
    }

    if (ds == -9999) {
        cout << "Err: " << ds << "\n";
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve_test();
        }
    }
    return 0;
}