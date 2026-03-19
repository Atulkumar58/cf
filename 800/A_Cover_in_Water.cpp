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

        int count_total=0, maxi=0;
        int counti=0;
        for(char c: s){
            if(c=='#'){
                counti=0;
            }
            else{
                counti++;
                maxi= max(maxi, counti);
                count_total++;
            }
        }

        if(maxi > 2){
            cout<< 2<<endl;
        }
        else{
            cout<<count_total<<endl;
        }
    }
    return 0;
}