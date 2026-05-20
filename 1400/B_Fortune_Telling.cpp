#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, x, y;
        cin>>n>>x>>y;

        vector<long long> a(n);
        long long sum = 0;
        for(long long& i: a) {cin>>i; sum^= i; }

        if((x^sum)%2 == (y%2)) cout<<"Alice\n";
        else cout<<"Bob\n";

    }
    return 0;
}