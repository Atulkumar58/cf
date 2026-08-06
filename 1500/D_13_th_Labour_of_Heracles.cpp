#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        long long sum=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
        }

        vector<int> freq(n, 0);
        for(int i=0; i<n-1; i++){
            int a, b;
            cin>>a>>b;

            freq[a-1]++;
            freq[b-1]++;
        }
        // for(int i=0; i<n; i++){
        //     cout<<freq[i]<<" ";
        // }cout<<endl;
        vector<int> v;
        for(int i=0; i<n; i++){
            int temp= freq[i]-1;
            for(int j=0; j<temp; j++){
                v.push_back(arr[i]);
            }
        }

        sort(v.begin(), v.end(), greater<int>());
        for(int i=0; i<v.size(); i++){
            cout<<sum<<" ";
            sum+= v[i];
        }
        cout<<sum<< endl;
    }
    return 0;
}