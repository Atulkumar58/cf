#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            int rem = x % k;
            if (rem == 0) rem = k;  // important trick

            v.push_back({-rem, i}); // negative for descending sort
        }

        sort(v.begin(), v.end());

        for (auto &p : v) {
            cout << p.second + 1 << " ";
        }
        cout << "\n";
    }
}