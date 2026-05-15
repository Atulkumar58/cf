#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count=0;
        for(char c:s) if(c =='(') count++;
                        else count--;
         
        if(n%2 == 1 || count != 0){
            cout<< -1 <<endl; continue;
        }
        
        vector<int> v(n);
        int open=0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                if(open >= 0){
                    v[i]=1;
                }
                else{
                    v[i]=2;
                }
                open++;
            }
            else{
                if(open > 0){
                    v[i]=1;
                }
                else{
                    v[i]=2;
                }
                open--;
            }
        }
        int ans=1;
        for(int i=1; i<n; i++){
            if(v[i] != v[i-1]){
                ans=2; break;
            }
        }

        if(ans==1){
            for(int& i: v) i=1;
        }

        cout<<ans<<endl;
        for(int i: v) cout<<i<<" ";
        cout<<endl;

    }
    return 0;
}