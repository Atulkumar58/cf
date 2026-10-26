#include <bits/stdc++.h>

using namespace std;

int searchceil(vector<int>& arr, int val){
    //values greater than val
    int i=0, j= arr.size()-1;
    while(i<=j){
        int mid= (i+j)/2;

        if(arr[mid] > val){
            j= mid-1;
        }
        else i= mid+1;
    }
    return arr.size()- i; // number of greater values
}
int searchfloor(vector<int>& arr, int val){
    //values smaller than val
    int i=0, j=arr.size()-1;
    while(i <= j){
        int mid= (i+j)/2;

        if(arr[mid] >= val){
            j= mid-1;
        }
        else i= mid+1;
    }
    return i; // number of smaller values
}
int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int& i: a) cin>>i;
    for(int& i:b) cin>>i;
    for(int& i:c) cin>>i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    // for(int i: a) cout<<i<<" "; cout<<endl;
    // for(int i: b) cout<<i<<" "; cout<<endl;
    // for(int i: c) cout<<i<<" "; cout<<endl;
    long long ans=0;
    for(int i=0; i<n; i++){
        int s= searchfloor(a, b[i]); // smaller than b
        int l= searchceil(c, b[i]); // grater than b

        ans+= ((long long)s*l);
        // cout<<s<<" "<<l <<" "<< ans<<endl;
    }
    cout<<ans;
}