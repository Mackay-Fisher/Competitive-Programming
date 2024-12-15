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
    unordered_map<ll, vector<pair<ll, ll> > > graph;
    for (ll i = 0; i < m; i++)
    {
        ll n1, n2;
        cin >> n1 >> n2;
        auto wnode = make_pair(n2 - 1, 1);
        auto wnode2 = make_pair(n1-1,1);
        graph[n1 - 1].push_back(wnode);
        graph[n2-1].push_back(wnode2);
    }
    vector<ll> distNode(n, INT32_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > graphq;
    distNode[0] = 0;
    graphq.push(make_pair(0, 0));
    // set debug staments of not
    bool debug = false;
    while (!graphq.empty())
    {
        ll curtVert = graphq.top().second;
        if (debug)
        {
            cout << "Current vertex: " << curtVert << endl;
        }
        graphq.pop();
        if (curtVert == n-1)
            break;

        for (const auto &vect : graph[curtVert])
        {
            ll nextVert = vect.first;
            ll w = vect.second;
            if (debug)
            {
                cout << "Next vertex: " << nextVert << " Weight: " << w << endl;
            }
            if (distNode[curtVert] + w < distNode[nextVert])
            {
                distNode[nextVert] = distNode[curtVert] + w;
                graphq.push(make_pair(distNode[nextVert], nextVert));
            }
        }
    }
    if (distNode[n-1]>n-1)
    {
        cout<<0<<endl;
    }else{       
        cout << max((ll)0,distNode[n-1]-1) << endl;
    }
}