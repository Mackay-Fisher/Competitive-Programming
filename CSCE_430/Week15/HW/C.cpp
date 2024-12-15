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
#include <numeric>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
void runP(ll n)
{
    vector<pair<ll,ll>> corners;
    for (int i = 0; i < n; i++)
    {
        ll a,b;
        cin>>a>>b;
        corners.push_back({a,b});
    }
    
}
int main()
{
    ll n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        runP(n);
    }
}