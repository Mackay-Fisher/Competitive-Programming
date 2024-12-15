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
vector<bool> vis(1000000, true);
int main()
{
    ll a;
    cin >> a;
    vector<ll> arrows;
    for (int i = 0; i < a; i++)
    {
        ll z;
        cin >> z;
        arrows.push_back(z);
    }
    ll prev = arrows[0];
    ll size = 0;
    ll cursub = false;
    vector<vector<ll>> subs;
    for (int i = 0; i < a; i++)
    {
        if (vis[i])
        {
            vector<ll> sub;
            sub.push_back(i);
            ll prev = arrows[i];
            ll local = 1;
            vis[i]= false;
            for (int j = i+1; j < a; j++)
            {
                if (prev == arrows[j] + 1 && vis[j])
                {
                    local++;
                    sub.push_back(j);
                    vis[j]= false;
                    prev--;
                }
            }
            subs.push_back(sub);
        }
    }
    // for(auto &a : subs){
    //     for(auto &b : a){
    //         cerr<<b<<"  ";
    //     }
    //     cerr<<endl;
    // }
    cout<<subs.size()<<endl;
    // cout<<size<<endl;
    // ll total = subs + size;
    // cout << total << endl;
    // cout << subs << endl;
    // ll rem = a - total;
    // cout << subs + rem << endl;
}