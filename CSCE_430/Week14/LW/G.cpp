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
vector<ll> bases(100000,0);
void fibs(){
    bases[0]=0;
    bases[1]= 2;
    bases[2] = 3;
    ll mod = 1e9 + 7;
    for(int i=3; i<100001; i++){
        bases[i] = ((bases[i-1] + bases[i-2]) % mod );
    }
}
int main(){
    ll t;
    cin>>t;
    fibs();
    while (t--)
    {
        ll a;
        cin>>a;
        cout<<bases[a]<<endl;
    }
    
}