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
bool processEdgeCases(ll kids, ll candy)
{
    bool edgeCase = false;
    if (kids == 1 && candy > 1)
    {
        cout << 1 << endl;
        edgeCase = true;
    }
    if (candy == 1)
    {
        cout << kids + 1 << endl;
        edgeCase = true;
    }
    return edgeCase;
}

pair<ll, ll> gcdInvCalc(ll candy, ll kids)
{
    ll xstart = 1, xstop = 0;
    ll quotient, remainder, xhold;
    while (kids)
    {
        quotient = candy / kids;
        remainder = candy % kids;
        candy = kids;
        kids = remainder;
        ll xhold = xstart - quotient * xstop;
        xstart = xstop;
        xstop = xhold;
    }
    return {candy, xstart};
}
void runP()
{
    ll kids, candy;
    cin >> kids >> candy;
    bool edgeCase = processEdgeCases(kids, candy);
    if (!edgeCase)
    {
        auto ret = gcdInvCalc(candy, kids);
        if (ret.first == 1)
        {
            ll revMod = (ret.second % kids + kids) % kids;
            if (revMod > 10e9)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
            cout << revMod << endl;
            return;
        }
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else
    {
        return;
    }
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