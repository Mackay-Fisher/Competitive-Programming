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
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll m,c;
        cin>>m>>c;
        unordered_map<ll, vector<pair<ll, ll>>> catMap;
        vector<pair<ll,pair<ll,ll> > >edgeList;
        ll lines = (c*(c-1))/2;
        CustomDJ UNF = CustomDJ();
        for (int i = 0; i < c; i++)
        {
            UNF.makeSet(i);
        }
        for(int i=0; i<lines; i++){
            ll a,b,c;
            cin>>a>>b>>c;
            edgeList.push_back({c,{a,b}});
            edgeList.push_back({c,{b,a}});
        }
        sort(edgeList.begin(),edgeList.end());
        vector<ld> finalLis;
        ll sum = 0;
        for(auto a: edgeList){
            if(UNF.findsetRescursive(a.second.first)!=UNF.findsetRescursive(a.second.second)){
                UNF.merge(a.second.first,a.second.second);
                sum+=a.first;
            }
        }
        if(m>=sum+c){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
}