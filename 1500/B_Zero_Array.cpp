#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    long long sum=0;
    int maxi= 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+= a[i];
        maxi= max(maxi, a[i]);
    }
    
    if(sum % 2 == 0 && maxi <= sum/2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}