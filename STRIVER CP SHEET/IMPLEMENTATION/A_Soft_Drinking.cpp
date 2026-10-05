#include <iostream>
#include <climits>
using namespace std;
int main(){
    int arr[8];
    for(int i=0; i<8; i++){
        cin>>arr[i];
    }

    int mini = INT_MAX;
    mini= min(mini, (arr[1]*arr[2])/arr[6]);
    mini= min(mini, (arr[3]*arr[4]));
    mini= min(mini, (arr[5]/arr[7]));

    cout<<mini/arr[0];
return 0;
}