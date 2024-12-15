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
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> stairs(11234);
vector<vector<ll> > dpJump(11234,vector<ll>(11234,-1));
ll dp(ll i, ll j, ll n){
    if (i == n-1) {
        return dpJump[i][j] = stairs[i];
    }
    
    if(dpJump[i][j]!=-1){
        return dpJump[i][j];
    }
    else{
    ll c1=1000000,c2=1000000;
        if(i-j >=0 && j!=0){
            c1 = dp(i-j, j, n);
        }
        if(i+j+1 <n){
            c2 = dp(i+j+1, j+1, n);
        }
        return dpJump[i][j] = stairs[i] + min(c1,c2);
    }
}
int main()
{
    ll n;
    cin>>n;
    
    for (int i = 0; i < n; i++)
    {
        cin>>stairs[i];
    }
    cout<<dp(0,0,n) - stairs[0] << endl;
    
    
}