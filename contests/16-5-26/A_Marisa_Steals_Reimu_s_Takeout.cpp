#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int n_one=0, n_two=0;
        for(int& i: a){
            cin>>i;
            if(i==1) n_one++;
            else if(i==2) n_two++;
        }
        int ans=0;
        if(n_one >= n_two){
            int t= n_one - n_two;
            ans += n_two;
            ans+= t/3;
        }
        else{
            int t= n_two - n_one;
            ans += n_one;
            ans += t/3;
        }
        ans+= (n-n_one - n_two);
        cout<<ans<<endl;
    }

    return 0;
}