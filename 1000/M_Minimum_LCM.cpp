#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==0){
            cout<<n/2<<" "<<n/2<<endl;
            continue;
        }
        int lcm= 1e9;
        int a=1, b=n-1;
        for(int i=1; i*i <= n; i++){
            if(n%i == 0){
                int x= n-i;
                if(x < lcm && x != 0){
                    lcm= x;
                    a= i;
                    b= x;
                }
                int j= n/i;
                x= n-j;
                if(x < lcm && x != 0){
                    lcm= x;
                    a= j;
                    b= x;
                }
            }

        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}