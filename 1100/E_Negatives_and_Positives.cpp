#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int countneg=0;
        int mini= INT_MAX;
        long long sum=0;
        for(int i=0; i<n; i++){ 
            cin>>a[i]; 
            if(a[i] < 0) countneg++; 
            mini= min(mini, abs(a[i]));
            sum+= abs(a[i]);
        }

        if(countneg % 2 == 0){
            cout<<sum<<endl;
        }
        else{
            cout<<sum - 2*mini<<endl;
        }
    }
    return 0;
}