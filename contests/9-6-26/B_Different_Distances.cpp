#include <iostream>
#include <vector>

using namespace std;



int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> ans;
        ans.reserve(4 * n);
        for(int i: ans){
            
        }
        for (int i = 1; i <= n; i++) ans.push_back(i);
        
        for (int i = 1; i <= n; i++) ans.push_back(i);
        
        for (int i = 2; i <= n; i++) ans.push_back(i);
            ans.push_back(1);
        
        for (int i = 1; i <= n; i++) ans.push_back(i);
        
        for (int i = 0; i < 4 * n; i++) {
            cout << ans[i] << (i == 4 * n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}