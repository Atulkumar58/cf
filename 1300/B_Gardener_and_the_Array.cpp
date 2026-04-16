#include <iostream>
#include <vector>

using namespace std;

// Frequency array to store how many times each bit index appears
int bit_counts[200005];

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> arrays(n);
    vector<int> distinct_bits;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        arrays[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> arrays[i][j];
            // If this is the first time we see this bit, track it for resetting
            if (bit_counts[arrays[i][j]] == 0) {
                distinct_bits.push_back(arrays[i][j]);
            }
            bit_counts[arrays[i][j]]++;
        }
    }

    bool found_redundant = false;
    for (int i = 0; i < n; i++) {
        bool all_bits_covered = true;
        for (int bit : arrays[i]) {
            // If any bit in this number appears ONLY here, this number isn't redundant
            if (bit_counts[bit] == 1) {
                all_bits_covered = false;
                break;
            }
        }
        
        if (all_bits_covered) {
            found_redundant = true;
            break;
        }
    }

    if (found_redundant) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    // Efficiently reset the frequency array for the next test case
    for (int bit : distinct_bits) {
        bit_counts[bit] = 0;
    }
}

int main() {
    // Fast I/O is important for Codeforces problems with large inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}