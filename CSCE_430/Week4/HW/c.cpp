#include<vector>
#include<iostream>
#include <utility>
#include <algorithm>
#include <string_view>
#include <unordered_map>
#include <numeric>
using namespace std;

int main(){
    vector< pair <long long,long long> > vals;
    long long a,b;
    cin>>a>>b;
    unordered_map<long long, long long> map;
    vector<long long> val;
    vector<int> v(a);
    iota(v.begin(),v.end(),0);
    for(long long i = 0; i<b; i++){
        long c,d;
        cin>>c>>d;
        vals.push_back(make_pair(d,c));
    }
    sort(vals.rbegin(),vals.rend());
    for (auto &a: vals)
    {
        long long swapVal = a.second;

        swap(v[a.second],v[a.second+1]);
    }
    for(int i=0; i<a; i++){
        cout<<v[i]<<" ";
    }
}

