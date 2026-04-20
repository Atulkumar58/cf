#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> factors;
        for(int i=2; i*i <= n; i++){
            if(n%i ==0){
                factors.push_back(i);
                n /= i;
                if(factors.size() == 2){
                    break;
                }
            }
        }
        if(n > 1 && factors.size()==2 && factors[1] != n) 
            factors.push_back(n);

        if(factors.size() < 3){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<factors[0]<<" "<<factors[1]<<" "<<factors[2]<<endl;
        }
    }
    return 0;
}