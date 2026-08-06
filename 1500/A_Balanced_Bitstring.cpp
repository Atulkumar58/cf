#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool possible= true;
        for(int i=0; i<k; i++){
            char c= '2';
            for(int j= i; j<n; j+= k){
                if(s[j] == '1'){
                    if(c == '0'){
                        possible = false;
                        break;
                    }
                    c= '1';
                }else if(s[j] == '0'){
                    if(c == '1'){
                        possible = false;
                        break;
                    }
                    c= '0';
                }
            }
            if(c != '2'){
                s[i] = c;
            }
            if(!possible){
                break;
            }
        }
        if(!possible){
            cout<<"NO"<<endl;
            continue;
        }
        int c=0;
        int q=0;
        for(int i=0; i<k; i++){
            if(s[i] == '1'){
                c++;
            }else if(s[i] == '0'){
                c--;
            }else q++;
        }
        if(abs(c) > q){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}