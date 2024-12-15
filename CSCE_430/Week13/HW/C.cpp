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
    ll ports;
    cin>>ports;
    vector<ll> arr(ports);
    vector<ll> l;
    for(int i = 0; i<ports; i++){
        cin>>arr[i];
    }
    for(int i=0; i<ports; i++){
        if(i==0){
            l.push_back(arr[i]);
        }else{
            auto index = lower_bound(l.begin(),l.end(),arr[i]);
            if(index==l.end()){
                l.push_back(arr[i]);
            }else{
                ll a = index - l.begin();
                l[a] = arr[i];
            }  
        }
    }
    cout<<l.size()<<endl;
}