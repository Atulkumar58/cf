
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(){
    int n;cin>>n;
    string s;cin>>s;
    int p=0, m=0;
    for(int i=0; i<n; i++){
        if(s[i]=='+') p++;
        else m++;
    }
    int diff= abs(p-m);
    int q;cin>>q;

    while(q--){
        int a, b;
        cin>>a>>b;

        int g= gcd(max(a, b), min(a, b));
        
        a/= g;
        b/= g;
        
        int d= abs(a-b);
        if(diff==0 || d==0 && diff==0) {cout<<"YES"<<endl; continue;}
        else if(d == 0) {cout<<"NO"<<endl; continue;}
        
        int x= diff%d;
        long long y= min(p, m) -((long long)diff/d)*min(a, b);
            if((x == 0) && (y >= 0) && a+b <= n) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        
        
    }
    return 0;
}