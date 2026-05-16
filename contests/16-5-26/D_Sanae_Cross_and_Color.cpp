#include <bits/stdc++.h>
using namespace std;

class Solver {
public:
    
    void process() {
        int n;
        cin >> n;

        vector<pair<int,int>> arr(n);
        vector<int> xs, ys;

        xs.reserve(n);
        ys.reserve(n);

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            arr[i] = {a, b};

            xs.push_back(a);
            ys.push_back(b);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        int X = xs.size();
        int Y = ys.size();

        vector<int> low(X, Y);
        vector<int> high(X, -1);

        for (auto &p : arr) {

            int cx = lower_bound(xs.begin(), xs.end(), p.first) - xs.begin();
            int cy = lower_bound(ys.begin(), ys.end(), p.second) - ys.begin();

            low[cx] = min(low[cx], cy);
            high[cx] = max(high[cx], cy);
        }

        vector<int> rightMin(X), rightMax(X);

        int mn = Y;
        int mx = -1;

        for (int i = X - 1; i >= 0; --i) {

            mn = min(mn, low[i]);
            mx = max(mx, high[i]);

            rightMin[i] = mn;
            rightMax[i] = mx;
        }

        long long ans = 0;

        int leftMin = Y;
        int leftMax = -1;

        for (int i = 0; i + 1 < X; i++) {

            leftMin = min(leftMin, low[i]);
            leftMax = max(leftMax, high[i]);

            int L = max(leftMin, rightMin[i + 1]);
            int R = min(leftMax, rightMax[i + 1]);

            if (R > L) {
                ans += (R - L);
            }
        }

        cout << ans << '\n';
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    Solver obj;

    while (T--) {
        obj.process();
    }

    return 0;
}