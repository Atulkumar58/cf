#include <iostream>
using namespace std;

bool check(long long n){
    long long int t= n;
    while(n>0){
        int digit = n%10;
        if(digit!=0 && t%digit !=0){
            return false;
        }
        n/=10;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        while(!check(n)){
            n++;
        }
        cout<<n<<endl;
    }
    return 0;
}