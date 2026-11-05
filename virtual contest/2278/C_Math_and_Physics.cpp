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
        int sum=0;
        bool two=false;
        for(int i=0; i<n; i++){
            cin>>a[i];
            sum+=a[i];
            if(a[i]>=2 && (i!=0 && i!= n-1)) two=true;
        }

        if(two){
            cout<<sum-1<<endl;
        }
        else if(a[0]>=2 || a[n-1]>=2){
            cout<<sum-(n-1)<<endl;
        
        }
        else{
            cout<<-1<<endl;
        }

    }
}