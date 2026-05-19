#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);
        long long ans=0;
        long long buffer=0;
        long long ones=0;
        int type_cards=0;
        for(int& i: a){
            cin>>i;
            if(i==1){
                ones++;
            } else if(i >= 2){
                ans+= i;
                type_cards++;
                buffer+= (i/2 -1);
            }
        }
        if(type_cards == 1){
            if(ones == 0 && ans<3){
                cout<<0<<endl;
            }
            else if(ones < ans/2){
                cout<<ans + ones<<endl;
            }
            else{
            cout << ans + (ans)/2<<endl;
            }
            continue;
        }
        cout<<ans + min(buffer, ones)<<endl;
    }
    return 0;
}