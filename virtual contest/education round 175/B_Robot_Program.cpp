#include <iostream>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, x, k;
        cin>>n>>x>>k;

        string s;
        cin>>s;
        
        long long time_left = k;
        long long  ans = 0;
        int time;
        for( time= 1; time <= n; time++){
            if(s[time-1] == 'L'){
                x--;
            }else x++;

            if(x == 0){
                ans++;
                break;
            }
        }
        if(time == n+1){
            cout<<0<<endl;
            continue;
        }
        time_left -= time;

        int count =0;
        long long time_round = LLONG_MAX;
        for(int i=0; i<n; i++){
            if(s[i] == 'L') count++;
            else count--;

            if(count == 0){
                time_round = i +1;
                break;
            }
        }
        ans+= time_left / time_round;

        cout<<ans<<endl;
    }
    return 0;
}