#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int a=-1, b=-1;
        int count=0;
        bool flag= true;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(a==-1 || a==arr[i]){
                 a=arr[i]; count++;
            }
            else if(b==-1 || b== arr[i]){
                b= arr[i]; count--;
            } 
            else flag= false;

        } 
        if(flag &&(b==-1 || (count<2 && count > -2))) cout<< "Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}