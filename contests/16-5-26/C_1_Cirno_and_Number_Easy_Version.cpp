#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string S;
    int n;
    if (!(cin >> S >> n)) return;

    vector<char> D(n);
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        D[i] = (char)('0' + e);
    }

    unsigned long long X = 0;
    for (char c : S) X = X * 10 + (c - 48);
    
    unsigned long long Y = -1ULL;

    auto chk = [&](string s) {
        if (s.empty() || (s.length() > 1 && s[0] == '0')) return;
        unsigned long long v = 0;
        for (char c : s) v = v * 10 + (c - 48);
        unsigned long long diff = (X >= v) ? (X - v) : (v - X);
        if (diff < Y) Y = diff;
    };

    int len = S.length();
    string cur = "";
    int i = 0;

    while (i < len) {
        char t = S[i];
        for (char g : D) {
            if (g != t) {
            
                string rem(len - 1 - i, (g < t) ? D[1] : D[0]);
                chk(cur + g + rem);
            }
        }
        if (t == D[0] || t == D[1]) {
            cur.push_back(t);
            i++;
        } else {
            break;
        }
    }

    if (cur.length() == len) chk(cur);
    if (len > 1) chk(string(len - 1, D[1]));

    char f = (D[0] != '0') ? D[0] : D[1];
    if (f != '0') chk(string(1, f) + string(len, D[0]));
    if (D[0] == '0') chk("0");

    cout << Y << "\n";
}

int main() {
    // Fast I/O
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