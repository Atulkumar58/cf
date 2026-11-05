#include <bits/stdc++.h>

using namespace std;
long long nSubstring(string s, string t){
    int n= s.length();
    vector<int> last(4, -1);
    long long ans=0;
    int start=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            if(s[i] == t[j]){
                if(j==0){
                    last[j]= i;
                }else{
                    if(j==3 && last[j] != last[j-1]){
                        int x= last[j-1]-start;
                        int y= n-i;
                        ans+= ((long long)x*y);
                        start= last[j-1];
                    }
                    last[j]= last[j-1];
                }
            }
        }
    }
    return ans;
}
long long both(string s){
    int n= s.length();
    string a="2025", b="2026";
    vector<int> lasta(4, -1);
    vector<int> lastb(4, -1);
    int start= -1;
    long long ans= 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            if(s[i] == a[j]){
                if(j==0){
                    lasta[j]=i;
                }
                else{
                    lasta[j]= lasta[j-1];
                }
            }

            if(s[i]==b[j]){
                if(j==0){
                    lastb[j]= i;
                }
                else{
                    lastb[j]= lastb[j-1];
                }
            }

            if(min(lasta[3], lastb[3])> start){
                int x= min(lasta[3], lastb[3])- start;
                int y= n-i;
                ans+= ((long long)x*y);
                start= min(lasta[3], lastb[3]);
            }
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        string s;
        cin>>s;

        long long total= (n* (n+1))/2;
        long long a= nSubstring(s, "2025");
        long long b= nSubstring(s, "2026");
        long long temp= a-both(s);
        cout<<total-temp<<endl;
    }
    return 0;
}