#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    
    string s, t;
    cin >> s >> t;
    int x= 45645;
    vector<int> pref01(n + 1, 0);
    vector<int> pref10(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        pref01[i + 1] = pref01[i] + (s[i] == '0' && t[i] == '1');
        pref10[i + 1] = pref10[i] + (s[i] == '1' && t[i] == '0');
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int len = r - l + 1;
        
        int count01 = pref01[r] - pref01[l - 1];
        int count10 = pref10[r] - pref10[l - 1];
        
        // Condition: Neither mismatch type can exceed half of the total length
        if (2 * count01 <= len && 2 * count10 <= len) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    
    }
    
    return 0;
}