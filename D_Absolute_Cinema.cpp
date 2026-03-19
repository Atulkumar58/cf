#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-12;
bool solveLinearSystem(vector<vector<long double>> &a, int n) {

    for(int i = 0; i < n; i++) {

        // 1️⃣ Find pivot
        int pivot = i;
        for(int j = i+1; j < n; j++)
            if(fabsl(a[j][i]) > fabsl(a[pivot][i]))
                pivot = j;

        // If pivot is zero → no unique solution
        if(fabsl(a[pivot][i]) < EPS)
            return false;

        // 2️⃣ Swap rows
        swap(a[i], a[pivot]);

        // 3️⃣ Normalize pivot row
        long double div = a[i][i];
        for(int j = i; j <= n; j++)
            a[i][j] /= div;

        // 4️⃣ Eliminate other rows
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            long double factor = a[j][i];
            for(int k = i; k <= n; k++)
                a[j][k] -= factor * a[i][k];
        }
    }

    // 5️⃣ Print answer
    cout << fixed << setprecision(10);
    for(int i = 0; i < n; i++)
        cout << (int)a[i][n] << " ";
    cout << "\n";

    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        vector<vector<long double>> a(n, vector<long double> (n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                a[i][j]= abs(i-j);
            }
        }

       
        // cout<<D<<" ";
        vector<int> ans;
        
            for(int j=0; j<n; j++){
                a[j].push_back(arr[j]);
            }
            bool d= solveLinearSystem(a, n);
            
        // cout<<endl;
    }
    return 0;
}