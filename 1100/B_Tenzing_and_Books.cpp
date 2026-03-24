#include <iostream>
#include <vector>


using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        for(int i=0; i<n; i++) cin>>c[i];
        
        int curr=0;
        for(int i=0; i<n; i++){
            int t= curr | a[i];
            if((t & ~x )!=0){
                break;
            } curr= t;
        }
        for(int i=0; i<n; i++){
            int t= curr | b[i];
            if((t & ~x )!=0){
                break;
            } curr= t;
        }
        for(int i=0; i<n; i++){
            int t= curr | c[i];
            if((t & ~x )!=0){
                break;
            } curr= t;
        }

        if(curr==x){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}