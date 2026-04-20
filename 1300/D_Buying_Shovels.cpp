#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        
        bool found = false;
        int value= -1;
        for(int i=1; i*i <= n; i++){
            if(n%i == 0){
                if(n/i <= k){
                    cout<<i<<endl;
                    found = true;
                    break;
                }
                else if(i <= k){
                    value= max(value, i);
                }
            }

            // if(n%i == 0 && i <= k){
            //     cout<<n/i<<endl;
            //     found = true;
            //     break;
            // }
        }

        
        if(!found){
            if(value != -1){
                cout<<n/value<<endl;
            }
        //     else
        //         cout<<n<<endl;
        }
    }
    return 0;
}