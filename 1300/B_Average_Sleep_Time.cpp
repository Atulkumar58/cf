#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    int k, n;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    long long sum = 0.0;
    long long window= 0.0;
    for(int i=0; i<k-1; i++){
        window+=a[i];
    }
    for(int i=k-1; i<n; i++){
        window+=a[i];
        sum+=window;
        window-=a[i-k+1];
    }

    cout<< setprecision(10) << (long  double)sum / (n-k+1) <<endl;
    return 0;
}