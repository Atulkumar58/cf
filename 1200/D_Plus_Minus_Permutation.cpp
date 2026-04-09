#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, x, y;
        cin>>n>>x>>y;

        long long g = gcd(x, y);
        long long lcm= ((x*y)/g);

        int c= n/lcm;
        int a= n/x -c;
        int b= n/y -c;

        long long ans = a*(2*n -a +1) /2;
        ans -= (long long)b*(b+1) /2;
        cout<< ans << endl;
    }
    return 0;
}