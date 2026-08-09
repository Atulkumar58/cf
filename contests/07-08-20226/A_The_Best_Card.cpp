#include <iostream>
#include <vector>
using namespace std;

vector<int> prime(1e5*2 + 1, 1);
void pre(){
    prime[0] = prime[1] = 0;
    for(int i = 2; i*i < prime.size(); i++){
        if(prime[i]){
            for(int j = i*i; j < prime.size(); j += i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    pre();
    while(t--){
        int n;
        cin>>n;
        if(prime[n+1]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}