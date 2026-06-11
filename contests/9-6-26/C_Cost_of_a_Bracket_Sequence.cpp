#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// DP State table helper
// dp[j][d] stores the max C (unmatched closing brackets)
void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    string s;
    cin >> s;

    // To implement the full solution with reconstruction under strict memory limits,
    // we use a 2-row DP to find the optimal configuration first, 
    // and then a Divide and Conquer approach if needed, or a compact bit-matrix.
    
    // Since sum of N <= 5000, a vector of vectors for a single test case is very fast.
    vector<vector<int>> dp(n + 2, vector<int>(k + 2, -1));
    dp[0][0] = 0; // base case: 0 open, 0 deletions -> 0 closed

    // For reconstruction, since sum of N <= 5000, N^2 elements total across test cases is small!
    // Wait! If sum of N <= 5000, then N for a single testcase is at most 5000.
    // The total size of a 3D table for ONE testcase of size N is N * J * D.
    // But notice: if we only allocate exactly what's needed per testcase, 
    // we can optimize the reconstruction path.
    
    // Let's implement the forward DP to find the minimum cost
    for (int i = 0; i < n; ++i) {
        vector<vector<int>> next_dp(n + 2, vector<int>(k + 2, -1));
        for (int j = 0; j <= i; ++j) {
            for (int d = 0; d <= min(i, k); ++d) {
                if (dp[j][d] == -1) continue;

                // Option 1: Delete s[i]
                if (d + 1 <= k) {
                    next_dp[j][d + 1] = max(next_dp[j][d + 1], dp[j][d]);
                }

                // Option 2: Keep s[i]
                if (s[i] == '(') {
                    next_dp[j + 1][d] = max(next_dp[j + 1][d], dp[j][d]);
                } else { // s[i] == ')'
                    if (j > 0) {
                        next_dp[j - 1][d] = max(next_dp[j - 1][d], dp[j][d]);
                    } else {
                        next_dp[0][d] = max(next_dp[0][d], dp[j][d] + 1);
                    }
                }
            }
        }
        dp = move(next_dp);
    }

    // Find the best final state
    int min_cost = n + 1;
    int best_j = -1, best_d = -1;
    for (int j = 0; j <= n; ++j) {
        for (int d = 0; d <= k; ++d) {
            if (dp[j][d] != -1) {
                int current_cost = (n - d) - (dp[j][d] + j);
                if (current_cost < min_cost) {
                    min_cost = current_cost;
                    best_j = j;
                    best_d = d;
                }
            }
        }
    }

    // Construct the result string by backtracking or a secondary pass
    string ans(n, '0');
    // ... Traceback logic goes here ...
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}