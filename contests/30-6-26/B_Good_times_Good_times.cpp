#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> g;

bool gd(long long n) {
    int m = 0;
    while (n > 0) {
        m |= (1 << (n % 10));
        n /= 10;
    }
    return __builtin_popcount(m) <= 2;
}

void pre() {
    
    for(int i= 2; i<10; i++){
        g.push_back(i);
    }
    int c_digit = 2;
    while(c_digit <= 9){
        int a, b;
        int na, nb;
        for(int i=0; i<10; i++){
            for(int j=i+1; j<10; j++){
                
            }
        }
    }
}

void solve() {
    long long x;
    cin >> x;

    int dm = 0;
    for (int i = 0; i < 3; ++i) dm += i;

    for (long long y : g) {
        if (y >= 2 && gd(x * y)) {
            cout << y << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}