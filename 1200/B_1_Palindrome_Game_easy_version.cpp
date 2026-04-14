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

        bool draw=true;
        int num_zero=0;
        for(char c: s){
            if(c == '0'){
                draw=false;
                num_zero++;
            }
        }

        if(draw){
            cout<<"DRAW"<<endl;
        }
        else if(n%2==1 && s[n/2] == '0' && num_zero > 1){
            cout<<"ALICE"<<endl;
        }
        else{
            cout<<"BOB"<<endl;
        }

    }
    return 0;
}