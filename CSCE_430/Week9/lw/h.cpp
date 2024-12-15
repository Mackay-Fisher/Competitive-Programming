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
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll> >houses;
    CustomDJ UNF = CustomDJ();
    for (int i = 1; i <=n; i++)
    {
        UNF.makeSet(i);
    }
    for (int i = 0; i <m; i++)
    {
        ll a,b;
        cin>>a>>b;
        UNF.merge(a,b);
    }
    ll parent = UNF.findsetRescursive(1);
    vector<ll> pass;
    for (int i = 1; i <=n; i++)
    {
        if (UNF.findsetRescursive(i) != parent)
        {
            pass.push_back(i);
        }
    }
    if(pass.size()==0){
        cout<<"Connected"<<endl;
    }
    else{
        for(auto &v : pass){
            cout<<v<<endl;
        }
    }
    
}