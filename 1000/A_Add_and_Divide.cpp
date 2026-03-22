#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int ans = INT_MAX;

        for (int k = 0; k <= 30; k++) {
            int new_b = b + k;

            if (new_b == 1) continue; // skip useless case

            int temp_a = a;
            int ops = k;

            while (temp_a > 0) {
                temp_a /= new_b;
                ops++;
            }

            ans = min(ans, ops);
        }

        cout << ans << "\n";
    }
}