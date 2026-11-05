#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        for(int& i: a) cin>>i;
        int idx= n-1;
        for(int i= n-1; i>n-k; i--){
            if(a[i] < a[idx]){
                idx= i;
            }
        }
        int idx2= n-k;
        for(int i= n-k; i>=0; i--){
            if(a[i] > a[idx2]){
                idx2= i;
            }
        }
        if(n-k >=a[idx2]){
            cout<<-1<<endl;
            continue;
        }
        cout<<idx2+1<<" "<<idx+1<<endl;
    }
}