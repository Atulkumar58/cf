#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        int size= pow(2, n);
        while(q--){
        string s;
        cin>>s;
        if(s=="->"){
            int x, y;
            cin>>x>>y;

            long long int ans=0;
            long long int p= (long long )size;
            while(p!=0){
                if(x> p/2 && y>p/2){
                    ans+= (p*p)/4;
                    x-= p/2;
                    y-=p/2;
                }else if(x> p/2 && y <= p/2){
                    ans+=(p*p)/2;
                    x-=p/2;
                }else if( x <= p/2 && y>p/2){
                    ans+=(p*p*3)/4;
                    y-= p/2;
                }
                p=p/2;
            }
            cout<<ans+1<<endl;
        }
        else{
            int num;
            cin>>num;
            int p=size;
            int grid= pow(p, 2);
            int x=1, y=1;
            while(p!=0){
                if(num > (grid*3)/4){
                    y+=p/2;
                    num-= (grid*3)/4;
                }
                else if( num > grid/2){
                    x+= p/2;
                    num-= (grid/2);
                }
                else if(num> grid/4){
                    x+=p/2;
                    y+=p/2;
                    num-= (grid/4);
                }
                grid/=4;
                p/=2;
                
            }
            cout<<x<<" "<<y<<endl;
        }
    }
    }
    return 0;
}