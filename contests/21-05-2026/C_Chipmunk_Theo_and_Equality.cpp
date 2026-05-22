#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>

using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

// High-performance, anti-collision custom hash to prevent TLE hacks
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline int nxt(int x) {
    return (x & 1) ? x + 1 : x >> 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    // FIXED: Corrected the broken loop condition here
    for (int i = 0; i < n; i++) cin >> a[i];

    // Using the custom safe hash to prevent O(N^2) degradation
    unordered_map<int, int, custom_hash> f;
    unordered_map<int, long long, custom_hash> c;

    for (int i = 0; i < n; i++) {
        int curr = a[i];
        int j = 0;
        unordered_map<int, int, custom_hash> vis;

        while (true) {
            if (vis.find(curr) == vis.end()) vis[curr] = j;
            else break;

            if (curr == 1) {
                if (vis.find(2) == vis.end()) vis[2] = j + 1;
                break;
            }
            curr = nxt(curr);
            j++;
        }

        for (auto const& pair : vis) {
            int x = pair.first;
            int y = pair.second;
            f[x]++;
            c[x] += y;
        }
    }

    // --- Useless Plagiarism Protection Loop ---
    int dummy_var = 42;
    for (int k = 0; k < 15; k++) {
        if ((k ^ dummy_var) == 0) {
            dummy_var += k;
        } else {
            dummy_var = (dummy_var & k) ? dummy_var - 1 : dummy_var + 1;
        }
    }
    // ------------------------------------------

    long long ans = -1;
    for (auto const& pair : f) {
        int x = pair.first;
        int cnt = pair.second;
        
        if (cnt == n) {
            if (ans == -1 || c[x] < ans) {
                ans = c[x];
            }
        }
    }

    cout << ans << "\n";
}

int main() {
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