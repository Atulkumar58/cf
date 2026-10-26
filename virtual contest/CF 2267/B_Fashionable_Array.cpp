#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(101,0);
        for(int i=0; i<n; i++){
            int t; cin>>t;
            a[t]++;
        }
        for(int i=100; i>=0; i--){
            int t= a[i];
            if(a[i] > 0){
                for(int j=i; j>=0; j--){
                    if(a[j] > 0){
                        int count=0;
                        while(a[j] >0 && count<t){
                            a[j]--;
                            count++;
                            cout<<j<<" ";
                        }
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}