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
vector<ll> order;
set<ll> found;
vector<ll> comp;
vector<vector<ll>> comps;
void dfsFor(ll v, unordered_map<ll, vector<ll>> &adj)
{
    found.insert(v);
    for (auto n : adj[v])
    {
        if (found.find(n) == found.end())
        {
            dfsFor(n, adj);
        }
    }
    order.push_back(v);
}
void dfsRev(ll v, unordered_map<ll, vector<ll>> &reverse)
{
    found.insert(v);
    comp.push_back(v);
    for (auto n : reverse[v])
    {
        if (found.find(n) == found.end())
        {
            dfsRev(n, reverse);
        }
    }
}

bool IsConnected(vector<pair<ll, ll>> roadMap, ll n)
{
    unordered_map<ll, vector<ll>> graph;
    unordered_map<ll, vector<ll>> revgraph;
    order.clear();
    found.clear();
    comp.clear();
    comps.clear();
    vector<ll> roads;
    for (auto &r : roadMap)
    {
        graph[r.first].push_back(r.second);
        revgraph[r.second].push_back(r.first);
    }

    for (int i = 0; i < n; i++)
    {
        if (found.find(i) == found.end())
        {
            dfsFor(i, graph);
        }
    }

    found.clear();
    reverse(order.begin(), order.end());
    for (auto x : order)
    {
        if (found.find(x) == found.end())
        {
            comp.clear();
            dfsRev(x, revgraph);
            comps.push_back(comp);
        }
    }
    return (comps.size()==1);
}

int main()
{
    ll m, n;
    ll cas = 1;
    while (cin >> m >> n)
    {
        cout << "Case " << cas << ": ";
        cas++;
        vector<pair<ll, ll>> roadMap;
        for (int i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            roadMap.push_back({a, b});
        }

        if (IsConnected(roadMap, m))
        {
            cout << "valid" << endl;
        }
        else
        {
            bool found = false;
            for (int i = 0; i < roadMap.size(); i++)
            {
                auto p = roadMap[i];
                auto p2 = make_pair(p.second, p.first);
                roadMap[i] = p2;
                if (IsConnected(roadMap, m))
                {
                    found = true;
                    cout << p2.second << " " << p2.first << endl;
                    break;
                }
                roadMap[i] = p;
            }
            if (!found)
            {
                cout << "invalid" << endl;
            }
        }
    }
}