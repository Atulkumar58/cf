#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;

        vector<int> tasks(m);
        vector<int> no_tasks(n+1, 0);
        for(int& i: tasks){
            cin>>i;
            no_tasks[i]++;
        }

        long long e=0;
        for(int i: no_tasks){
            if(i>e){
                e= i;
            }
        }

        long long s=1;
        while(s <= e){
            long long mid= (s+e)/2;

            //test if it is possible to complete all tasks in mid days
            long long tasks=0;
            for(int i=1; i<=n; i++){
                if(no_tasks[i]>=mid){
                    tasks += (no_tasks[i]-mid);
                }
                else{
                    tasks -= ((mid-no_tasks[i])/2);
                }
            }

            if(tasks > 0){
                s= mid+1;
            }
            else{
                e= mid-1;
            }
        }
        cout<<s<<"\n";  

    }
    return 0;
}