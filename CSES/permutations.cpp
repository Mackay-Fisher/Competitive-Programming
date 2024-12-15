#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <tuple>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }
    if(n<4){
        cout<<"NO SOLUTION"<<endl;
    }else{
        vector<ll> even;
        vector<ll> odd;
        for(int i=1; i<=n; i++){
            if(i%2==0){
                even.push_back(i);
            }else{
                odd.push_back(i);
            }
        }
        for(int i=0; i<even.size(); i++){
            cout<<even[i]<<" ";
        }
        for(int i=0; i<odd.size(); i++){
            cout<<odd[i]<<" ";
        }
        cout<<endl;
    }
}