#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p, q;
        if (!(cin >> p >> q)) return 0;
        bool found = false;
        while(p >= 0 && q >= 0) {
            //p= b-a

            long long dis= (p+3)*(p+3) + 4*(2*q);
            
            if(dis > 0){
                long long v= sqrt(dis);
                long long a= (-(p+3) + v) / 2.0;
                long long b= p+a;
                if(a> 0 && b>0 && a -(long long)(int)a == 0 && b -(long long)(int)b == 0){
                    cout << a << " " << b << endl;
                    found = true;
                    break;
                }
            }
            p -= 2;
            q += 1;
        }
        if (!found) {
            cout << -1 << endl;
        }
    }
    return 0;
}