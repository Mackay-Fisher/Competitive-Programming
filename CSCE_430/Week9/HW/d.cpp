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
int main()
{
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, vector<ll> > grpah;
    vector<ll> indgree(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        // cout<<a<<"   "<<b<<endl;
        grpah[a].push_back(b);
        indgree[b]++;
    }
    vector<ll> startNodes;
    for (int i = 1; i <= n; i++)
    {
        if (!indgree[i])
        {
            startNodes.push_back(i);
        }
    }
    vector<ll> order;
    set<ll> visit;
    for (int i = 0; i < startNodes.size(); i++)
    {
        queue<ll> q;
        q.push(startNodes[i]);
        while (!q.empty())
        {
            auto topN = q.front();
            q.pop();
            // cout<<topN<<endl;
            if (visit.find(topN) != visit.end())
            {
                // cout<<"kill me"<<endl;
                break;
            }
            visit.insert(topN);
            order.push_back(topN);
            for (auto &a : grpah[topN])
            {
                // cout<<a<<endl;
                indgree[a]--;
                if (!indgree[a])
                {
                    q.push(a);
                }
            }
        }
    }

    if (order.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (auto &a : order)
        {
            cout << a << endl;
        }
    }
}