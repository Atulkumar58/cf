#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool flag= false;
        int count=0;
        int length=s.length();
        for(int i=1; i<n; i++){
            if(s[i]== s[i-1]){
                length--;
            }
            else if(i+1<n && s[i] != s[i-1] && s[i] != s[i+1]){
                count++;
            }
            
            if(i!= n-1 && s[i-1] == s[i+1] && s[i] != s[i-1]){
                flag= true;
            }
        }
        // cout<<length<<" "<<count<<" "<<flag<<endl;
        if(length <= 2){
            cout<<length<<endl;
        }
        else if(flag){
            cout<<length-2<<endl;
        }
        else if(count>0){
            cout<<length-1<<endl;
        }else{
            cout<<length<<endl;
        }
    }
    return 0;
}