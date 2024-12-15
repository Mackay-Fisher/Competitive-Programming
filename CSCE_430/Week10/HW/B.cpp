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
bool checkConnection(unordered_map<ll,set<ll> >& graph, ll size){
    queue<ll> q;
    set<ll> visit;
    q.push(0);
    ll localSize = 0;
    vector<ll> nodes;
    while (!q.empty())
    {
        auto to = q.front();
        q.pop();
        if(visit.find(to)!=visit.end()){
            continue;
        }
        visit.insert(to);
        nodes.push_back(to);
        for(auto &a: graph[to]){
            if (visit.find(a)==visit.end())
            {
                q.push(a);
            }
        }
    }
    return localSize == size;
}

int main(){
    while (true)
    {
        ll p,c;
        cin>>p>>c;
        if (p==0 && c==0)
        {
            break;
        }
        unordered_map<ll,set<ll> > graph;
        vector<pair<ll,ll> > edgeList;
        for (size_t i = 0; i < c; i++)
        {
            ll a,b;
            cin>>a>>b;
            graph[a].insert(b);
            graph[b].insert(a);
            edgeList.push_back(make_pair(a,b));
        }
        bool canbreak = false;
        for(auto &a: edgeList){
            graph[a.first].erase(a.second);
            graph[a.second].erase(a.first);
            if(!checkConnection(graph,p)){
                canbreak = true;
                break;
            }
            graph[a.first].insert(a.second);
            graph[a.second].insert(a.first);
        }
        if(canbreak){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
        
    }
    
}