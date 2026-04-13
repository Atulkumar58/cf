#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char c;
        cin>>c;
        string s;
        cin>>s;

        bool flag= true;
        int one_ans=-1;
        for(int i=n-1; i>=0; i--){
            if(s[i] != c){
                flag= false;
            }
            else{
                if(2* (i+1) > n){
                    one_ans= i;
                }
            }
        }
        if(flag){
            cout<<0<<endl;
        }
        else if(one_ans != -1){
            cout<<1<<endl;
            cout<<one_ans+1<<endl;
        }
        else{
            cout<<2<<endl;
            cout<<n-1<<" "<<n<<endl;
        }
    }
    return 0;
}