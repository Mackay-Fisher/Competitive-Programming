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
ll LCI(vector<ll> arr){
    vector<ll> l;
    for(int i=0; i<arr.size(); i++){
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
    return l.size();
}



ll runProgram(){
    ll n, p, q;
    cin>>n>>p>>q;
    ll size = n*n;
    vector<ll> pmoves(p+1);
    unordered_map<ll,ll> princeMap;
    vector<ll> qmoves(q+1);
    for(int i=0; i<p+1; i++){
        cin>>pmoves[i];
        princeMap[pmoves[i]] = (i+1); 
    }
    vector<ll> LCIArray;
    for(int i=0; i<q+1; i++){
        cin>>qmoves[i];
        LCIArray.push_back(princeMap[qmoves[i]]);
    }
    return LCI(LCIArray);

}


int main(){
    ll t;
    cin>>t;
    for(int i=0; i<t; i++){
        cout<<"Case "<< (i+1) <<": "<<runProgram()<<endl;
    }
}