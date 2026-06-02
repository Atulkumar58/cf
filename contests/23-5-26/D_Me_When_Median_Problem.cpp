#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if a target value X is achievable
bool can_achieve(int n, const vector<int>& a, const vector<int>& b, int X) {
    // binary_a[i] = 1 if a[i] >= X else 0
    // binary_b[i] = 1 if b[i] >= X else 0
    vector<int> val_a(n), val_b(n);
    for (int i = 0; i < n; ++i) {
        val_a[i] = (a[i] >= X) ? 1 : 0;
        val_b[i] = (b[i] >= X) ? 1 : 0;
    }

    // If n == 1, we just need both to be >= X
    if (n == 1) {
        return (val_a[0] == 1 && val_b[0] == 1);
    }

    // DP or reachability array: standard check for median-like propagation
    // For an element to reach the end, we look for configurations 
    // where '1's can successfully cluster and eliminate '0's.
    for (int i = 0; i < n - 1; ++i) {
        int count = val_a[i] + val_a[i+1] + val_b[i] + val_b[i+1];
        // If any 2x2 window has 3 or more elements >= X, 
        // we can definitely expand this window to cover the whole array.
        if (count >= 3) {
            return true;
        }
        // If a window has exactly 2 ones, they must be aligned in a way
        // that allows propagation depending on neighboring context.
        if (count == 2) {
            // If the two ones are in the same column or staggered vertically
            if ((val_a[i] && val_b[i]) || (val_a[i+1] && val_b[i+1])) {
                return true;
            }
        }
    }

    // If we only have isolated ones or single matches at the boundaries
    // Check if the initial positions allow a chain reaction
    // A stable configuration is also when val_a[i] == 1 and val_b[i] == 1
    for (int i = 0; i < n; ++i) {
        if (val_a[i] == 1 && val_b[i] == 1) {
            return true;
        }
    }

    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int max_val = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        max_val = max(max_val, b[i]);
    }

    // Binary search range for the maximum possible min(a_1, b_1)
    int low = 1, high = max_val, ans = 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_achieve(n, a, b, mid)) {
            ans = mid;       // mid is possible, try a larger value
            low = mid + 1;
        } else {
            high = mid - 1;  // mid is impossible, try smaller values
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
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