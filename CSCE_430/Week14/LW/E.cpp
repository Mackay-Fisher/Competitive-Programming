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
ll bfs(unordered_map<ll, vector<ll>> &map, ll &start, vector<bool> &vis)
{
    queue<ll> q;
    q.push(start);
    ll size = 0;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        if (vis[cur])
        {
            continue;
        }
        vis[cur] = true;
        size++;
        for (auto &a : map[cur])
        {
            if (!vis[a])
            {
                q.push(a);
            }
        }
    }
    return size;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, l;
        cin >> n >> m >> l;
        unordered_map<ll, vector<ll>> vmap;
        for (int i = 0; i < m; i++)
        {
            ll a, b;
            cin >> a >> b;
            // cout<<a<<b<<endl;
            vmap[a].push_back(b);
        }

        vector<bool> vis(n + 1);
        ll size = 0;
        for (int i = 0; i < l; i++)
        {
            ll s;
            cin >> s;
            size+=bfs(vmap, s, vis);
        }
        // cout<<s<<endl;
        cout << size << endl;
    }
}