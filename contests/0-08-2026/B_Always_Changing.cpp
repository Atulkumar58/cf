#include <iostream>
using namespace std;
bool check(int a, int b){
     if(a==b || a+1==b || a==b+1){ return true; } 
     else return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int a=0, b=0;
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                if(s[i] == '0') a++;
                else b++;
            }
        }
        int t= a+b;
        if(check(a,b)){
            cout<<t<<endl; continue;
        }
        if(s[0] == '0' && a < b) a++;
        if(b< a && s[0] == '1') b++;

        if(check(a,b)){
            cout<<a+b<<endl; continue;
        }

        if(s[n-1] == '0' && a < b) a++;
        if(b< a && s[n-1] == '1') b++;
        if(check(a,b)){
            cout<<a+b<<endl; continue;
        }
        else cout<<-1<<endl;
    }
    return 0;
}