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
    ll test;
    cin>> test;
    while (test--)
    {
        ll l;
        cin>>l;
        ll start,size,time;
        cin>>start>>size>>time;
        ll med;
        cin>>med;
        vector<ll> medVec;
        for(int i =0; i<med; i++){
            ll a;
            cin>>a;
            medVec.push_back(a);
        }
        ll r;
        cin>>r;
        vector<unordered_map<ll,pair<ll,ll>>> map(r+1);
        for(int i=0; i<r; i++){
            ll a,b,p,t;
            cin>>a>>b>>p>>t;
            map[a][b] = {p,t};
            map[b][a] = {p,t};
        }
    }
    
}