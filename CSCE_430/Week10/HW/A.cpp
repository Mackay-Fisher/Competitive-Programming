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
class CustomDJ {
    private:

    public:
    unordered_map<long long, long long> p;  
    unordered_map<int, int> maxVal; 
    unordered_map<long long, long long> size;
    set<long long> uniqueParents;
    long long  maxValue = 0;
    //This will recursivley find the value of teh base of the set
    long long findsetRescursive(long long x){
        if(p[x]==x) return x;
        //Path compression to set the parent of teh current set to the base
        p[x]=findsetRescursive(p[x]);
        return p[x];
    }
    //This will merge base on the value of the max height and then adjust the pointer of the parent to the higher value or just adjust
    void merge(long long a,long long b){
        long long x,y;
        //We find teh sets associated with the values passed in to merge
        x = findsetRescursive(a);
        y = findsetRescursive(b);
        p[x]=y; 
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
    cin>>t;
    while(t--){
        ll sc,o;
        cin>>sc>>o;
        vector<pair<ld,ld> > outposts;
        // cout<<sc<<"   "<<o<<endl;
        for (int i = 0; i < o; i++)
        {
            ld a,b;
            cin>>a>>b;
            // cout<<a<<"   "<<b<<endl;
            outposts.push_back(make_pair(a,b));
        }
        vector< pair<ld,pair<ll,ll> > >edgeList;
        for (int i = 0; i < o; i++)
        {
            for (int j = i+1; j < o; j++)
            {
                auto a = outposts[i];
                auto b = outposts[j];
                ld distance = sqrt(pow(b.first-a.first,2) + pow(b.second-a.second,2));
                edgeList.push_back(make_pair(distance,make_pair(i,j)));
                edgeList.push_back(make_pair(distance,make_pair(j,i)));
            }
        }
        sort(edgeList.begin(),edgeList.end());
        unordered_map<ll, pair<ll,ld> >wgraph;
        CustomDJ UNF = CustomDJ();
        for (int i = 0; i < o; i++)
        {
            UNF.makeSet(i);
        }
        vector<ld> finalLis;
        for(auto a: edgeList){
            if(UNF.findsetRescursive(a.second.first)!=UNF.findsetRescursive(a.second.second)){
                UNF.merge(a.second.first,a.second.second);
                finalLis.push_back(a.first);
            }
        }
        cout<<fixed<<setprecision(2)<<finalLis[o-sc-1]<<endl;
        // for (auto &a: finalLis)
        // {
        //     cout<<a<<endl;
        // }
    }
}