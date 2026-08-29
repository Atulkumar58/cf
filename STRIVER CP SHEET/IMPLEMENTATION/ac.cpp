#include <iostream>
using namespace std;
int main(){
    long long a;
    cin>>a;
    long long mask= 1e18;
    bool start = false;
    for(int i=18; i>=0; i--){
        int digit= (a/mask)%10;
        if((digit == 0  || digit == 9) && !start){
            if(digit == 9) start = true;
            mask /= 10;
            continue;
        }
        start = true;
        if(digit > 9-digit){
            a-= digit*mask;
            a+= (9-digit)*mask;
        }
        mask /= 10;
    }
    cout<<a;
return 0;
}

