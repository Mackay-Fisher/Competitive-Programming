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
ld minBetweenSegments(pair<ll, ll> i1, pair<ll, ll> o0, pair<ll, ll> o1)
{
    pair<ll, ll> vecAB = {(o1.first - o0.first), (o1.second - o0.second)};
    pair<ll, ll> vecAP = {(i1.first - o0.first), (i1.second - o0.second)};
    ld proj = (vecAB.first * vecAP.first) + (vecAB.second * vecAP.second);
    ld norm2 = (vecAB.first * vecAB.first) + (vecAB.second * vecAB.second);
    ld val = proj / norm2;
    pair<ld, ld> closest;
    //I looked up the method to 
    if (val < 0.0)
    {
        closest = o0;
    }
    else if (val > 1.0)
    {
        closest = o1;
    }
    else
    {
        closest = {o0.first + val * vecAB.first, o0.second + val * vecAB.second}; // Point on the segment
    }

    pair<ld, ld> pv = {i1.first - closest.first, i1.second - closest.second};
    ld distance = sqrt(pv.first * pv.first + pv.second * pv.second);
    return distance;
}

void runP()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> Innerpoints;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        Innerpoints.push_back({a, b});
    }
    ll nv;
    cin >> nv;
    vector<pair<ll, ll>> Outerpoints;
    for (int i = 0; i < nv; i++)
    {
        ll a, b;
        cin >> a >> b;
        Outerpoints.push_back({a, b});
    }
    ld minV = 441329857143598;
    for (auto &a : Innerpoints)
    {
        for (int i = 0; i < nv; i++)
        {
            auto a1 = Outerpoints[i];
            auto a2 = Outerpoints[(i + 1) % nv];
            minV = min(minBetweenSegments(a, a1, a2), minV);
        }
    }
    cout <<fixed<<setprecision(8)<<minV/2 << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        runP();
    }
}