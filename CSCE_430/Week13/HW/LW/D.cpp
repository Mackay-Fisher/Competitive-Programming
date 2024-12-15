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
    priority_queue<pair<ld, ll>> graphq;
    vector<ld> distNode(10000, -1);
    distNode[startCannon] = 1;
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
                cout<<nextVert<<" "<<distNode[nextVert]<<endl;
            }
            if (distNode[curtVert] * w > distNode[nextVert])
            {
                distNode[nextVert] = distNode[curtVert] * w;
                graphq.push({distNode[nextVert], nextVert});
            }
        }
    }
    return distNode[endCannon];
}
int main()
{
    ll a,b;
    while(cin>>a>>b){
        if(a==0 && b==0){
            break;
        }
        ll end = a-1;
        unordered_map<ll, vector<pair<ll, ld>>> mapV;
        for(int i=0; i<a; i++){
            ll a,b;
            ld c;
            cin>>a>>b>>c;
            mapV[a].push_back({b,c});
            mapV[b].push_back({a,c});
        }
        ld val = djakstarts(mapV,0,end);
        cout<<fixed<<setprecision(4)<<val<<endl;
    }
}