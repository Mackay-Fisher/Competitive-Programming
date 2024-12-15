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
ll nextid = 0;
ll checkConnection(unordered_map<ll, set<ll> > &graph, vector<ll> &order, vector<ll> &low, ll curnode, ll parent)
{
    if(order[curnode]!=-1){
        return low[curnode];
    }
    order[curnode] = nextid;
    low[curnode] = nextid;
    nextid++;
    for(auto &a: graph[curnode]){
        if(a!=parent){
            low[curnode] = min(low[curnode], checkConnection(graph,order,low,a,curnode));
        }
    }
    return low[curnode];
}

int main()
{
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, set<ll> > graph;
    vector<pair<ll, ll> > edgeList;
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
        edgeList.push_back({a,b});
    }
    vector<ll>order(n,-1);
    vector<ll> low(n,-1);
    checkConnection(graph,order,low,0,-1);
    set<pair<ll,ll> > bridges;
    for(auto &a: edgeList){
        ll x =a.first, y=a.second;
        if(low[x]>order[y]){
            bridges.insert(a);
            continue;
        }
        if(low[y]>order[x]){
            bridges.insert(a);
            continue;
        }
    }
    // for(auto &a: bridges){
    //     cout<<a.first<<"   "<<a.second<<endl;
    // }
    queue<ll> q;
    set<ll> visit;
    ll localSize = 0;
    vector<ll> nodes;
    q.push(0);
    while (!q.empty())
    {
        auto to = q.front();
        q.pop();
        if(visit.find(to)!=visit.end()){
            continue;
        }
        visit.insert(to);
        localSize++;
        for(auto &a: graph[to]){
            if (visit.find(a)==visit.end() && bridges.find({to,a})==bridges.end() && bridges.find({a,to}) == bridges.end())
            {
                q.push(a);
            }
        }
    }
    cout<<visit.size()<<endl;
    // sort(edgeList.begin(), edgeList.end());
    // set<ll> cur;
    // for (int i = 0; i < n; i++)
    // {
    //     cur.insert(i);
    // }
    // for (auto &a : edgeList)
    // {
    //     if (cur.find(a.first) != cur.end() && cur.find(a.second) != cur.end())
    //     {
    //         // cout<<a.first<<"  "<<a.second<<endl;
    //         graph[a.first].erase(a.second);
    //         graph[a.second].erase(a.first);
            
    //         graph[a.first].insert(a.second);
    //         graph[a.second].insert(a.first);
    //     }else{
    //         break;
    //     }
    // }
    // for (auto &a: cur)
    // {
    //     cout<<a<<endl;
    // }
    // cout<<cur.size()<<endl;
    
}