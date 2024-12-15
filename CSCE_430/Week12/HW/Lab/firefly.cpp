// Keep two arrays, one (a[]) for stalagmites, one (b[]) for stalactites,
// giving number of each ending at that height
// • For each stalagmite, if it is height x, increment a[x]; similar for b/stalactites
// • At most 500,000 heights, so, a and b are size no bigger than that.
// • Then, use a prefix-sum to calculate the number of stalagmites that
// height or smaller (and similar for stalactites). Call these c[] and d[].
// • e.g. c[i] is number of stalagmites that height or smaller: c[i]=c[i-1]+a[i]
// • Go through all heights to find minimum (and record how many times)
// • c[i] + d[H-i-1] is the total number at any one height
// • Can do this without computing c, d explicitly if you want: start with n/2
// stalagmites, and at each height subtract a[i], and add b[H-i-1].
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

    ll n, h;
    cin >> n >> h;
    vector<ll> bottom(h, 0);
    vector<ll> top(h, 0);
    for (int i = 0; i < n; i++)
    {
        ll v;
        cin >> v;
        if (i % 2 == 0)
        {
            bottom[v-1]++;
        }
        else
        {
            top[h - v]++;
        }
    }

    vector<ll> c(h, 0);
    vector<ll> d(h, 0);
    for (int i = h-2; i>=0; i--)
    {
        c[i] = c[i + 1] + bottom[i];
    }
    for (int i = 1; i < h; i++)
    {
        d[i] = d[i - 1] + top[i];
    }
    // for(auto i: c){
    //     cerr << i << " ";
    // }
    // cout<<endl;
    // for(auto i: d){
    //     cerr << i << " ";
    // }
    // cout<<endl;
    // cout<<endl;
    ll minVal = INT32_MAX;
    ll count = 0;
    for (int i = 0; i < h; i++)
    {
        ll temp = c[i] + d[i];
        if (temp < minVal)
        {
            minVal = temp;
            count = 0;
        }
        if (temp == minVal)
        {
            count++;
        }
    }
    cout << minVal << " " << count << endl;
}