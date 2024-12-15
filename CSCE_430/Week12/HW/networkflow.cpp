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
        parents.assign(parents.size(),-1);
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
        vector<ll> parents(sink+2, -1);
        ll flow = 0;
        while (findAugmentingPathUsingBFS(source, sink, parents, map, capacity))
        {
            // cerr<<"Make it to the first path"<<endl;
            ll temp = sink;
            ll pathFlow = INT32_MAX;
            while (temp != source)
            {
                ll u = parents[temp];
                pathFlow = min(pathFlow,capacity[u][temp]);
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
            flow+=pathFlow;
        }
        return flow;
    }

};

int main(){
    ll n,m;
    cin>>n>>m;
    unordered_map<ll, vector<ll>> con; // gopholes[a][b] --> from, to
    vector<vector<ll>> capacity(n + m + 2, vector<ll>(n + m + 2, 0));
    for(int i=0; i<m; i++){
        ll a,b,c;
        cin>>a>>b>>c;
        con[a].push_back(b);
        con[b].push_back(a);
        capacity[a][b] += c;
        // if(capacity[b][a]){

        // }
        // capacity[b][a] = 0;
    }
    edmundsKarp karp = edmundsKarp();
    ll maxflow = karp.maxFlow(1,n,con,capacity);
    cout<<maxflow<<endl;
}