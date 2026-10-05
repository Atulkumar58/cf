#include <iostream>
#include <climits>
using namespace std;
int main(){
    int arr[3];
    int maxi= INT_MIN;
    int mini= INT_MAX;
    for(int i=0; i<3; i++){
        cin>>arr[i];
        maxi= max(maxi, arr[i]);
        mini= min(mini, arr[i]);
    }
    cout<<maxi-mini;
return 0;
}   