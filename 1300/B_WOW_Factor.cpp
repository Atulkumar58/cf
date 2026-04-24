#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    cin>>s;

    vector<int> a;
    long long count=0;
    long long sum=0;
    for(char c: s){
        if(c=='v'){
            count++;
        }
        else{
            if(count > 1){
                sum += (count-1);
                
                // cout<<sum<<" ";
            }
            a.push_back(sum);
            count=0;
        }
    }

    int i=s.length()-1, j=a.size()-1;
    count= sum = 0;
    long long ans=0;
    while(i >= 0 && j >= 0){
        if(s[i]=='v'){
            count++;
        }
        else{
            if(count > 1){
                sum += (count-1);
            }
            ans += (sum * a[j]);
            // cout<<a[j] <<" "<<sum <<" "<<ans<<endl;
                 j--;
            count=0;
        }
        i--;
    }
    cout<<ans<<endl;
    return 0;
}