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
    ll a;
    cin>>a;
    vector<ll> vals;
    for(int i=0; i<a; i++){
        ll v;
        cin>>v;
        vals.push_back(v);
    }
    vector<ll> bestR(a);
    vector<ll> bestL(a);
    ll maxR = 0;
    ll maxL = 0;
    for(int i=0; i<a; i++){
        maxL = max(maxL ,vals[i]);
        bestL[i] = maxL;
    }

    for(int i=a-1; i>=0; i--){
        maxR = max(maxR ,vals[i]);
        bestR[i] = maxR;
    }
    ll best = 0;
    for(int i=0; i<a; i++){
        ll local = min(bestL[i],bestR[i]);
        best = max(best, (local-vals[i]));
    }
    cout<<best<<endl;
}