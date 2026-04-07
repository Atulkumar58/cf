#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int limit = 200000;
    bool isP[limit + 1];
    
    for (int i = 0; i <= limit; i++) isP[i] = true;
    
    isP[0] = isP[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (isP[i]) {
            for (int j = i * i; j <= limit; j += i)
                isP[j] = false;
        }
    }

    long long p[15000];
    int cnt = 0;
    for (int i = 2; i <= limit && cnt < 15000; i++) {
        if (isP[i]) p[cnt++] = i;
    }

    int tc;
    if (!(cin >> tc)) return 0;
    
    while (tc--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            long long val = p[i] * p[i + 1];
            cout << val << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}