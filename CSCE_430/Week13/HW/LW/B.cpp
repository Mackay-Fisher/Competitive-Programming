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
#include <algorithm>
#include <set>
#include <map>
#include <tuple>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll l,n;
        cin>>l>>n;
        ll minT = -1;
        ll maxT = -1;
        vector<pair<ll,ll>> positions(n);
        for(int i=0; i<n; i++){
            ll a;
            cin>>a;
            ll minV = min(l- a,a);
            ll maxV = max(l- a,a);
            minT = max(minT,minV);
            maxT = max(maxV,maxT);
        }
        cout<<minT<<" "<<maxT<<endl;
    }
    
}