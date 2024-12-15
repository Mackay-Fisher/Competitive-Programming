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
#include <algorithm>
#include <set>
#include <map>
#include <tuple>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
class edmundsKarp
{
public:
    bool findAugmentingPathUsingBFS(ll start, ll sink, vector<ll> &parents, unordered_map<ll, vector<ll>> &map, vector<vector<ll>> &capacity)
    {
        queue<ll> q;
        q.push(start);
        parents.assign(parents.size(), -1);
        set<ll> vist;
        vist.insert(start);
        while (!q.empty())
        {
            ll node = q.front();
            q.pop();
            // cerr<<node<<endl;
            for (auto nei : map[node])
            {
                // cerr<<node<<"   "<<nei<<"    "<<capacity[node][nei]<<endl;
                if (!vist.count(nei) && capacity[node][nei] > 0)
                {
                    parents[nei] = node;
                    if (nei == sink)
                    {
                        return true;
                    }
                    q.push(nei);
                    vist.insert(nei);
                }
            }
        }
        return false;
    }

    ll maxFlow(ll source, ll sink, unordered_map<ll, vector<ll>> &map, vector<vector<ll>> &capacity)
    {
        vector<ll> parents(sink + 2, -1);
        ll flow = 0;
        while (findAugmentingPathUsingBFS(source, sink, parents, map, capacity))
        {
            // cerr<<"Make it to the first path"<<endl;
            ll temp = sink;
            ll pathFlow = INT32_MAX;
            while (temp != source)
            {
                ll u = parents[temp];
                pathFlow = min(pathFlow, capacity[u][temp]);
                temp = u;
            }
            // cerr<<pathFlow<<endl;
            temp = sink;
            while (temp != source)
            {
                ll u = parents[temp];
                capacity[u][temp] -= pathFlow;
                capacity[temp][u] += pathFlow;
                temp = u;
            }
            flow += pathFlow;
        }
        return flow;
    }
};

void runTest(ll n, ll m, ll s, ll v)
{
    vector<pair<ld, ld>> gophers;
    // unordered_map<ll, pair<ld, ld>> gmap;
    vector<pair<ld, ld>> holes;
    // unordered_map<ll, pair<ld, ld>> hmap;
    unordered_map<ll, vector<ll>> gopHoles; // gopholes[a][b] --> from, to
    vector<vector<ll>> capacity(n + m + 2, vector<ll>(n + m + 2, 0));
    // vector<unordered_map<int,ll>>
    ld maxDis = s * v + 0.00000001;
    for (int i = 0; i < n; i++)
    {
        ld x, y;
        cin >> x >> y;
        gophers.push_back({x, y});
    }
    for (int i = 0; i < m; i++)
    {
        ld x, y;
        cin >> x >> y;
        holes.push_back({x, y});
    }
    // all my nodes, source, sink
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < m + n; j++)
        {
            ld dis = sqrt(pow(gophers[i].first - holes[j - n].first, 2) + pow(gophers[i].second - holes[j - n].second, 2));
            if (dis <= maxDis)
            {
                gopHoles[i].push_back(j);
                gopHoles[j].push_back(i);
                capacity[i][j] = 1;
                capacity[j][i] = 0;
            }
        }
    }

    ll source = n + m;
    for (int i = 0; i < n; i++)
    {
        gopHoles[source].push_back(i);
        capacity[source][i] = 1;
    }
    ll sink = n + m + 1;
    for (int i = n; i < m + n; i++)
    {
        gopHoles[i].push_back(sink);
        capacity[i][sink] = 1;
    }
    // cerr<<"Made the grpah"<<endl;

    // for(auto & a: gopHoles){
    //     cerr<<a.first<<" :";
    //     for(auto &c : a.second){
    //         cerr<<c<<"   ";
    //     }
    //     cerr<<endl;
    // }

    ll maxHoles;
    edmundsKarp maxflow = edmundsKarp();
    maxHoles = maxflow.maxFlow(source, sink, gopHoles, capacity);
    cout << n-maxHoles << endl;
}

int main()
{
    ll n, m, s, v;
    while (cin >> n >> m >> s >> v)
    {
        runTest(n, m, s, v);
    }
}