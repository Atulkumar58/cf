#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> segments(n);
        int e=0;
        for(int i=0; i<n; i++){
            int l, r;
            cin>>l>>r;
            segments[i] = {l, r};
            e = max(e, r);
        }

        int s=0;
        while(s <= e){
            int mid = s + (e-s)/2;
            int mini=0, maxi=0;
            bool possible = true;
            for(int i=0; i<n; i++){
                // if(segments[i][0] > maxi){
                //     maxi += mid;
                //     maxi= min(maxi, segments[i][1]);
                //     mini = max(mini, segments[i][0]);
                // }
                // else if(segments[i][1] < mini){
                //     mini -= mid;
                //     mini = max(mini, segments[i][0]);
                //     maxi = min(maxi, segments[i][1]);
                // }
                // else{
                    mini -= mid;
                    maxi += mid;
                    mini = max(mini, segments[i][0]);
                    maxi = min(maxi, segments[i][1]);
                // }
                // cout<<"mini: "<<mini<<" maxi: "<<maxi<<endl;
                if(mini > maxi){
                    possible = false;
                    break;
                }
            }

            if(possible){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}