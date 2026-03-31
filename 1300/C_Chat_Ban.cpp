#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long k, x;
        cin>>k>>x;
        
        bool flag = false;
        long long s= 1, e= 2*k -1;
        while(s<=e){
            long long mid= s+(e-s)/2;
            long long sum=0;
            
            if(mid <= k){
                sum= (mid*(mid+1))/2;
            }
            else{
                long long n= mid- k;
                sum= (k*(k+1))/2 + (n*(k-1+ k-n))/2;
            }
           

            if(sum>x){
                e= mid-1;
            }
            else if(sum < x){
                s= mid+1;
            }else{
                cout<<mid<<endl;
                flag= true;
                break;
            }
        }
        if(!flag) cout<<min(s, 2*k-1)<<endl;
    }
    return 0;
}