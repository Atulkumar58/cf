#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;cin>>s;
        bool a=false,b=false;
        for(int i=0; i<s.size(); i++){
            if(a== 0 && s[i]=='0'){
                a=1;
                continue;
            }
            if(b== 0 && s[i]=='1'){
                b=1;
                continue;
            }

            cout<<s[i];
        }cout<<endl;
    }
    return 0;
}