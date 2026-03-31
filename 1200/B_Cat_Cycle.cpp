#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;

        if(n %2 ==0){
            cout<< (k - 1)%n +1 <<endl;
        }
        else{
            //initially -1 n
            // 1 -> 0 , n-1
            int initialb= 1;
            k--;
            if(k == 0 ) cout<<1<<endl;
            else{
                long long  step = n/2;
                long long jump = n/2 + 1;

                long long ans= k/ step * jump + initialb;
                long long rem = k % step;
                ans += rem;
                cout<< (ans-1) % n  +1 <<endl;
            }
        }

    }
    return 0;
}