#include <iostream>

using namespace std;
int mostsignificantbit(int n){
    int k=0;
    while(n>1){
        n= n>>1;
        k++;
    }
    return k;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int k= mostsignificantbit(n-1);
        int x=n-1;
        while(x >= (1<<k)){
            cout<<x<<" ";
            x--;
        }
        for(int i=0; i< (1<<k); i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}