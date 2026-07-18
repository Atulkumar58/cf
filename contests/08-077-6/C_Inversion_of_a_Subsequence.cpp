#include <iostream>
#include <vector>
using namespace std;

int main(){
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        int ones_to_zero = 0;
        bool has_change = false;
        
        bool c1 = false, c2 = false;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]){
                if(a[i] == 1) c1 = true;
                else c2 = true;
                continue;
            } 

            has_change = true;
            if(a[i] == 1) {
                ones_to_zero++;
            }
        }

        if(!has_change){
            cout << 0 << "\n";
        }
        else if(ones_to_zero % 2 == 1){
            cout << 1 << "\n";
        }
        else if(ones_to_zero > 0 || (c1 && c2)){
            cout << 2 << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }

    return 0;
}