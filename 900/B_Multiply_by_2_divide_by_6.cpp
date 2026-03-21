#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int a=0, b=0;
        while(n%2 == 0 && n%3==0){
            n/=6;
            a++;
        }
        while(n%3==0) {
            n/=3;
            b++;
        }

        if(n!= 1){
            cout<<-1<<endl;
        }
        else{
            cout<<a+b*2<<endl;
        }
    }
    return 0;
}