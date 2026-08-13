#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        if(n == k+1){
            cout<<-1<<endl;
            continue;
        }

        string s;
        int a= k/2;
        int b= k-a;
        for(int i=0; i<=a; i++){
            s+= '0';
        }
        for(int i=0; i<=b; i++){
            s+= '1';
        }

        while(s.length() < n){
            if(s.back() == '0'){
                s+= '1';
            }
            else{
                s+= '0';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}