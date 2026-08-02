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
        string s;
        vector<int> x(n); // xor array 1
        int temp=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            temp^= a[i];
            x[i] = temp;
        }
        cin>>s;
        int xor_z=0;
        int xor_o=0;
        for(int i=0; i<n; i++){
            if(s[i]== '1'){
                xor_o^= a[i];
            }else{
                xor_z ^= a[i];
            }
        }

        int q;
        cin>>q;
        while(q--){
            int type;
            cin>>type;
            if(type==1){
                int l,r;
                cin>>l>>r;
                // l--; r--;
                int a= x[r-1];
                int b= (l!=1) ? x[l-2] : 0;
                xor_o^= (a^b);
                xor_z^= (a^b);
            }
            else{
                int b;
                cin>>b;
                if(b) cout<<xor_o<<" ";
                else cout<<xor_z<<" ";
            }
        }cout<<endl;
    }
    return 0;
}