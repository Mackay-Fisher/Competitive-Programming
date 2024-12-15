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
int main()
{
    ll t;
    cin >> t;
    vector<pair<pair<ld,ld>,string>> runs;
    vector<string> names;
    vector<unordered_map<ll, string>> name;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        names.push_back(s);
        ld a, b;
        cin >> a >> b;
        runs.push_back({{b,a},s});
        // name[b][a] = s;
    }
    sort(runs.begin(),runs.end());
    ll count = 0;
    ld minSUm = INTMAX_MAX;
    vector<ll> inds;
    vector<ll> finalL;
    ll start = -1;
    for(int i=0; i<runs.size(); i++){
        count = 1;
        ld sum = runs[i].first.second;
        inds.clear();
        for(int j=0; j<runs.size(); j++){
            if(count == 4){
                if(sum<minSUm){
                    minSUm = sum;
                    finalL = inds;
                    start = i;
                }
                break;
            }
            if(i==j){
                continue;
            }else{
                count++;
                inds.push_back(j);
                sum+=runs[j].first.first;
            }
            
        }
    }
    cout<<fixed<<setprecision(10)<<minSUm<<endl;
    cout<<runs[start].second<<endl;
    for(auto a: finalL){
        cout<<runs[a].second<<endl;
    }
}