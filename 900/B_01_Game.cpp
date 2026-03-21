#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cz=0, co=0;
        for(char c:s) {
            if(c=='0') cz++;
            else co++;
        }

        int t= min(cz, co);
        if(t%2) cout<<"DA"<<endl;
        else cout<<"NET"<<endl;
    }
    return 0;
}