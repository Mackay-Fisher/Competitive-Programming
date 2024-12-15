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
ld djakstarts(unordered_map<ll, vector<pair<ll, ld>>> &cannonG, ll startCannon, ll endCannon)
{

    vector<ld> distNode(100000, INT32_MAX);
    priority_queue<pair<ll, ld>, vector<pair<ll, ld>>, greater<pair<ll, ld>>> graphq;
    distNode[startCannon] = 0.0;
    graphq.push(make_pair(0.0, startCannon));
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
        if (curtVert == endCannon)
        {
            break;
        }
        for (auto vect : cannonG[curtVert])
        {
            ll nextVert = vect.first;
            ld w = vect.second;
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
    return distNode[endCannon];
}
int main()
{
    ld x, y;
    cin >> x >> y;
    ld rx, ry;
    cin >> rx >> ry;
    ll n;
    cin >> n;
    vector<ll> cannon;
    vector<pair<ld, ld>> edgeList;
    for (int i = 0; i < n; i++)
    {
        ld a, b;
        cin >> a >> b;
        edgeList.push_back({a, b});
        cannon.push_back(i + 1);
    }
    unordered_map<ll, vector<pair<ll, ld>>> cannonG;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ld distance = sqrt(pow(abs(edgeList[i].first - edgeList[j].first), 2) + pow(abs(edgeList[i].second - edgeList[j].second), 2));
            ld time = 0;
            if (distance > 50.0)
            {
                time = (distance - 50.0) / 5 + 2;
            }
            else
            {
                time = 2 + abs(distance - 50.0)/5.0;
            }
            cannonG[cannon[i]].push_back({cannon[j], time});
            cannonG[cannon[j]].push_back({cannon[i], time});
        }
    }
    for (int i = 0; i < n; i++)
    {
        ld time = sqrt(pow(abs(edgeList[i].first - x), 2) + pow(abs(edgeList[i].second - y), 2)) / 5.0;
        cannonG[cannon[i]].push_back({n + 1, time});
        cannonG[n + 1].push_back({cannon[i], time});
    }
    for (int i = 0; i < n; i++)
    {
        ld dis = sqrt(pow(abs(edgeList[i].first - rx), 2) + pow(abs(edgeList[i].second - ry), 2));
        if (dis > 50.0)
        {
            dis = 2 + (dis - 50.0) / 5.0;
        }
        else
        {
            dis = 2 + abs(dis - 50.0)/5.0;
        }
        cannonG[cannon[i]].push_back({n + 2, dis});
        cannonG[n + 2].push_back({cannon[i], dis});
    }
    ld dis = sqrt(pow(abs(x - rx), 2) + pow(abs(y - ry), 2))/5.0;
    cannonG[n+1].push_back({n + 2, dis});
    cannonG[n+2].push_back({n + 1, dis});
    cout <<fixed<<setprecision(6)<<djakstarts(cannonG,n+1,n+2) << endl;
}