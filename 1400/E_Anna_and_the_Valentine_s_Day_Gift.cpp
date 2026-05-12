#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        int count_digits = 0;
        vector<int> zeros;
        for(int i=0; i<n; i++){
            int num = a[i];
            bool flag= false;
            int c=0;
            while(num > 0){
                int digit = num % 10;
                if(!flag && digit == 0){
                    c++;
                }
                else {
                    flag = true;
                }
                count_digits++;
                num /= 10;
            }
            if(c > 0){
                zeros.push_back(c);
            }
        }

        sort(zeros.begin(), zeros.end(), greater<int>());
        int total_digits = count_digits;
        for(int i=0; i<zeros.size(); i+=2){
            total_digits -= zeros[i];
        }

        if(total_digits <= m){
            cout<<"Anna"<<endl;
        }else{
            cout<<"Sasha"<<endl;
        }
    }
    return 0;
}