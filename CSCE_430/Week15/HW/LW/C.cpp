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
int main(){
    vector<bool> found(365,false);
    ll n;
    cin>>n;
    vector<ll> vec;
    for(int i=0; i<n; i++){
        ll a;
        cin>>a;
        vec.push_back(a);
    }
    vector<vector<ll>> subs;
    for (int i = 0; i < n; i++)
    {
        if (!found[i])
        {
            vector<ll> sub;
            sub.push_back(i);
            ll end = vec[i]+19;
            found[i]= true;
            for (int j = i+1; j < n; j++)
            {
                if (vec[j]<=end)
                {
                    sub.push_back(j);
                    found[j]= true;
                }
            }
            subs.push_back(sub);
        }
    }

    cout<<subs.size()<<endl;
}