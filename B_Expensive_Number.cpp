#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;

        cin>>s;
        int c=0;
        int n= s.length();
        int z=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                z++;
            }
        }
        int i=n-1;
        while(s[i] =='0'){
            z--;
            i--;
        }
       
        cout<<n-z-1<<endl;
    }
    
    return 0;
}