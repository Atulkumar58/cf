#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k, m;
        cin >> n >> k >> m;
        
        //dumy
        int sum = 0;
        for(int i=0; i<100; i++){
            sum+= i;
        }
        if (k > m) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) {
                if (i % k == 0) {
                    cout << (m - k + 1) << (i == n ? "" : " ");
                } else {
                    cout << 1 << (i == n ? "" : " ");
                }
            }
            cout << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}