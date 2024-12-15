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
class edmundsKarp
{
public:
    bool findAugmentingPathUsingBFS(ll start, ll sink, vector<ll> &parents, unordered_map<ll, vector<ll>> &map, unordered_map<ll, unordered_map<ll, ll>> &capacity)
    {
        queue<ll> q;
        q.push(start);
        parents.assign(parents.size(), -1);
        // set<ll> vist;
        // vist.insert(start);
        parents[start] = -2;
        while (!q.empty())
        {
            ll node = q.front();
            q.pop();
            // cerr<<node<<endl;
            for (auto nei : map[node])
            {
                // cerr<<node<<"   "<<nei<<"    "<<capacity[node][nei]<<endl;
                if (parents[nei] == -1 && capacity[node][nei] > 0)
                {
                    parents[nei] = node;
                    if (nei == sink)
                    {
                        return true;
                    }
                    q.push(nei);
                    // vist.insert(nei);
                }
            }
        }
        return false;
    }

    ll maxFlow(ll source, ll sink, unordered_map<ll, vector<ll>> &map, unordered_map<ll, unordered_map<ll, ll>> &capacity)
    {
        vector<ll> parents(source + 2, -1);
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

int main()
{
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> grid(h, vector<ll>(w));
    // vector<vector<ll>> capacity(2*(h * w) + 8, vector<ll>(2*(h * w) + 8, 0));
    unordered_map<ll, unordered_map<ll, ll>> capacity;
    unordered_map<ll, vector<ll>> bmap;
    ll offset = h*w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ll val;
            cin >> val;
            ll in = i * w + j;
            ll out = in + offset;
            capacity[in][out] = val;
            capacity[out][in] = 0;
            grid[i][j] = val;
            bmap[in].push_back(out);
            bmap[out].push_back(in);
        }
    }
    ll source = 2*(h * w);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 || j == 0 || i == h - 1 || j == w - 1)
            {
                bmap[source].push_back(i * w + j);
                capacity[source][(i*w+j)] = INT32_MAX;
                capacity[i*w+j][source] = 0;
                bmap[i*w+j].push_back(source);
            }
            ll in = i * w + j;
            ll out = in + offset;
            if (i > 0)
            {

                ll next = (i - 1) * w + j;
                bmap[out].push_back(next);
                capacity[out][next] = INT32_MAX;
                capacity[next][out] = 0;
                bmap[next].push_back(out);
            }
            if (i < h - 1)
            {
                ll next = (i + 1) * w + j;
                bmap[out].push_back(next);
                capacity[out][next] = INT32_MAX;
                capacity[next][out] = 0;
                bmap[next].push_back(out);
            }
            if (j > 0)
            {
                ll next = i * w + j - 1;
                bmap[out].push_back(next);
                capacity[out][next] = INT32_MAX;
                capacity[next][out] = 0;
                bmap[next].push_back(out);
            }
            if (j < w - 1)
            {
                ll next = i * w + j + 1;
                bmap[out].push_back(next);
                capacity[out][next] = INT32_MAX;
                capacity[next][out] = 0;
                bmap[next].push_back(out);
            }
        }
    }
    ll x, y;
    cin >> x >> y;
    ll sink = (x * w + y) + offset;
    // for(int i =0; i < 2*(h*w)+1; i++){
    //     cerr<<i<<": ";
    //     for(auto &a : bmap[i]){
    //         cerr<<a<<" ";
    //     }
    //     cerr<<endl;
    // }
    edmundsKarp Karp = edmundsKarp();
    ll minCut = Karp.maxFlow(source,sink,bmap,capacity);
    cout<<minCut<<endl;
}