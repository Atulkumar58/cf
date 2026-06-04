#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Helper function to check if a maximum penalty of 'mid' is possible with <= k operations
bool isValid(int mid, int n, int k, const string& s, const vector<int>& a) {
    int count = 0;
    bool painting = false;

    for (int i = 0; i < n; i++) {
        if (a[i] > mid) {
            if (s[i] == 'B') {
                if (!painting) {
                    count++;
                    painting = true; // Start a painting operation
                }
            } else { // s[i] == 'R'
                painting = false; // Must stop painting to avoid exceeding 'mid' penalty
            }
        }
    }
    return count <= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<int> a(n);
    int max_val = 0;
    for (int &i : a) {
        cin >> i;
        max_val = max(max_val, i);
    }

    int start = 0;
    int e = max_val;
    int ans = max_val;

    // Binary search for the minimum possible maximum penalty
    while (start <= e) {
        int mid = start + (e - start) / 2;

        if (isValid(mid, n, k, s, a)) {
            ans = mid;        // mid is possible, record it
            e = mid - 1;      // Try to find a smaller maximum penalty
        } else {
            start = mid + 1;  // mid is too small, increase the allowed penalty
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}