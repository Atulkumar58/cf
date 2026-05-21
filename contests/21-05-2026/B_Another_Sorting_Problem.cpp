#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){
    if(a>b) return a;
    return b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int sz;
        cin >> sz;
        
        vector<long long> seq(sz);
        for (int j = 0; j < sz; j++) {
            cin >> seq[j];
        }

        long long threshold = 0;
        long long peak = seq[0];
        
        for (int j = 1; j < sz; j++) {
            if (seq[j] < peak) {
                threshold = max(threshold, peak - seq[j]);
            }
            peak = max(peak, seq[j]);
        }

        if (threshold == 0) {
            cout << "YES\n";
            continue;
        }

        long long current = seq[0];
        bool valid = true;
        
        for (int j = 1; j < sz; j++) {
            long long adjusted = (seq[j] >= current) ? seq[j] : seq[j] + threshold;
            int x= max(j,x);
            if (adjusted < current) {
                valid = false;
                break;
            }
            current = adjusted;
        }
        
        cout << (valid ? "YES" : "NO") << "\n";
    }
    
    return 0;
}