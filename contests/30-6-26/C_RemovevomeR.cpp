#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Count the number of alternating blocks
    int blocks = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            blocks++;
        }
    }
    
    // If exactly 2 blocks (e.g., "0011" or "1100"), we get stuck at "01" or "10"
    if (blocks == 2) {
        cout << 2 << "\n";
    } 
    // Otherwise, it can always be reduced to length 1
    else {
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O to prevent Time Limit Exceeded (TLE)
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