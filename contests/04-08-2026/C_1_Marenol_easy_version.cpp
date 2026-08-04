#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a, b;
        cin>>a>>b;
        int ca=0, cb=0;
        bool change= false;
        bool same= false;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                if(a[i] == '1'){
                    ca++;
                }else ca--;
                if(b[i] == '1'){
                    ca--;
                }else ca++;
            }else{
                if(a[i] == '1'){
                    cb++;
                }else cb--;
                if(b[i] == '1'){
                    cb--;
                }else cb++;
            }

            if(a[i] != b[i]) change= true;
            if(i>0 && i<n-1 && a[i] == b[i]) same= true;
        }

        if(ca == 0 && cb == 0 && !(change ^ same)){
            cout<<"YES"<<endl;
        } else cout<<"NO"<<endl;
    }
    return 0;
}