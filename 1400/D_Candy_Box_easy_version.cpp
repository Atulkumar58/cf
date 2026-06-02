#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>> n ;
        vector<int> arr(n, 0);
        // vector<int> arr2(n, 0);
        // for(int &i: arr) cin>> i; arr2[i]++;}
        for(int i=0; i<n; i++){
            int x;
            cin>> x;
            arr[x-1]++;
        }
        sort(arr.begin(), arr.end(), greater<int>());
        long long ans = 0;
        int expected = INT_MAX;
        for(int i=0; i<n; i++){
            if(expected == 0 || arr[i] == 0) break;
            if(arr[i] > expected){
                ans += expected;
                expected = max(0, expected-1);
            }
            else{
                ans += arr[i];
                expected = max(0, arr[i]-1);
            }
        }
        cout<< ans << endl;
    }
    return 0;
}