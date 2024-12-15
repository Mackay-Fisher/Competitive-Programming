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
ld calcDistance(pair<ll,pair<ll,ll>> a,pair<ll,pair<ll,ll>> b){
    ld val = sqrt(pow((a.second.first-b.second.first),2) + pow((a.second.second-b.second.second),2));
    ld r = a.first+b.first;
    ld dis = max((ld)0, ld(val-r));
    return dis;
}
class CustomDJ
{
private:
public:
    unordered_map<long long, long long> p;
    unordered_map<int, int> maxVal;
    unordered_map<long long, long long> size;
    set<long long> uniqueParents;
    long long maxValue = 0;
    // This will recursivley find the value of teh base of the set
    long long findsetRescursive(long long x)
    {
        if (p[x] == x)
            return x;
        // Path compression to set the parent of teh current set to the base
        p[x] = findsetRescursive(p[x]);
        return p[x];
    }
    // This will merge base on the value of the max height and then adjust the pointer of the parent to the higher value or just adjust
    void merge(long long a, long long b)
    {
        long long x, y;
        // We find teh sets associated with the values passed in to merge
        x = findsetRescursive(a);
        y = findsetRescursive(b);
        p[x] = y;
    }
    void makeSet(long long x)
    {
        if (p.find(x) == p.end())
        {
            p[x] = x;
        }
    }
};
int main()
{
    ll t;
    cin >> t;
    unordered_map<ld, vector<pair<ll, ll>>> catMap;
    vector<pair<ld, pair<ll, ll>>> edgeList;
    CustomDJ UNF = CustomDJ();
    for (int i = 0; i < t; i++)
    {
        UNF.makeSet(i);
    }
    vector<pair<ld, pair<ll, ll>>> gather;
    for (int i = 0; i < t; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        gather.push_back({c, {a, b}});
    }
    for (int i = 0; i < t; i++)
    {
        for(int j = i+1; j<t; j++){
            ld distance = calcDistance(gather[i],gather[j]);
            edgeList.push_back({distance, {i, j}});
            edgeList.push_back({distance, {j, i}});
        }
    }
    sort(edgeList.begin(), edgeList.end());
    vector<ld> finalLis;
    ld sum = 0;
    for (auto a : edgeList)
    {
        if (UNF.findsetRescursive(a.second.first) != UNF.findsetRescursive(a.second.second))
        {
            UNF.merge(a.second.first, a.second.second);
            sum += a.first;
        }
    }
    cout<<fixed<<setprecision(8)<<sum<<endl;
}