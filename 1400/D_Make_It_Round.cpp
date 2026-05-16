#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;

        int temp = n;
        int two=0, five=0;
        while(temp%2==0){
            two++;
            temp/=2;
        }
        while(temp%5==0){
            five++;
            temp/=5;
        }
        long long ans=1;
        if(two >= five){
            temp= two- five;
            while(temp--){
                if(ans*5 <= m){
                    ans*=5;
                }else{
                    break;
                }
            }
        }else{
            temp= five- two;
            while(temp--){
                if(ans*2 <= m){
                    ans*=2;
                }else{
                    break;
                }
            }
        }
        while(ans*10 <= m){
            ans*=10;
        }

        temp= 10;
        while(temp ){
            if((ans*temp) <= m){
                ans*= temp;
                // cout<<ans<<" ";
                break;
            }
            temp--;
        }
        cout<< n* ans<<endl;
    }
    return 0;
}