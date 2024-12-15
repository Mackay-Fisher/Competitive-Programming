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
bool greedyPossible(ll &b, vector<ll> &cars){
    //need to track locomotives and traincars
    
}


void execute()
{
    ll n, m, l;
    cin >> n >> m >> l;
    vector<ll> listedCars(n,0);
    for (int i = 0; i < m; i++)
    {
        ll a;
        cin >> a;
        listedCars[a - 1]=1;
    }
    ll r = 0, l = n-1, mid = INT32_MAX;
    while (r<l)
    {
        ll mid = (l+r)/2;
        if(greedyPossible(mid,listedCars,l)){
            r = mid;
        }else{
            l = mid;
        }
    }
}

int main()
{
    ll tc;
    cin >> tc;
    for (int q = 0; q < tc; q++)
    {
        execute();
    }
}