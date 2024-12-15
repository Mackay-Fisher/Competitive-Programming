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
    cin >> n;
    unordered_map<string, vector<string> > graph;
    for (ll i = 0; i < n; i++)
    {
        string ingred;
        cin >> ingred;
        graph[ingred] = vector<string>();
    }
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        string pirIndA, pirIndB;
        cin >> pirIndA >> pirIndB;
        graph[pirIndA].push_back(pirIndB);
        graph[pirIndB].push_back(pirIndA);
    }
    queue<string> stqu;
    unordered_map<string, ll> connectionMap;
    vector<string> top;
    vector<string> bottom;
    set<string> graphSet;
    for (auto &vects : graph)
    {
        connectionMap[vects.first] = 0;
    }
    for (auto &vects : graph)
    {
        if (graphSet.find(vects.first) == graphSet.end())
        {
            stqu.push(vects.first);
            while (!stqu.empty())
            {
                auto to = stqu.front();
                // cout<<to<<endl;
                stqu.pop();
                if (graphSet.find(to) == graphSet.end())
                {

                    graphSet.insert(to);
                    //pushes back base state
                    if (!connectionMap[to])
                    {
                        top.push_back(to);
                    }
                    else
                    {
                        bottom.push_back(to);
                    }
                    for (auto &nodes : graph[to])
                    {
                        if (!connectionMap[nodes])
                        {
                            // This makes conatct with the other node meaning we hcnage it's vlaue to the opposit one that touched it.
                            if (connectionMap[to])
                            {
                                connectionMap[nodes] = 0;
                                stqu.push(nodes);
                            }
                            else
                            {
                                connectionMap[nodes] = 1;
                                stqu.push(nodes);
                            }
                        }
                        else
                        {
                            if (connectionMap[nodes] == connectionMap[to])
                            {
                                cout << "impossible" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    for (auto &vals : top)
    {
        cout << vals << " ";
    }
    cout << endl;
    for (auto &vals : bottom)
    {
        cout << vals << " ";
    }
}