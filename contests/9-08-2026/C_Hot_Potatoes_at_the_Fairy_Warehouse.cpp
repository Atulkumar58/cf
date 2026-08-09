#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool x= (s[0] == '0' && s[2*n-1] == '1')? true : false;
        for(int i=0; i<2*n-1; i++){
            if(s[i] == '1' && s[i+1] == '0'){
                swap(s[i], s[i+1]);
                i++;
            }
        }
        if(x){
            s[0]='1';
            s[2*n-1]='0';
        }

        int a=0, b=0;
        for(int i=0; i<2*n; i++){
            if(s[i] == '1'){
                if(i%2 == 1) a++;
                else b++;
            }
        }
        cout<<a<<" "<<b<<endl;
    }
    
    return 0;
}