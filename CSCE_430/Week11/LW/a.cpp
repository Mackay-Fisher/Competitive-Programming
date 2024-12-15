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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> res;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        res.push_back({a, a + b});
    }
    sort(res.begin(), res.end());
    ll count = 1;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++)
    {
        ll start = res[i].first, end = res[i].second;
        if (pq.empty())
        {
            pq.push(end + m);
        }
        else
        {
            while (!pq.empty() && pq.top() < start)
            {
                pq.pop();
            }
            if(pq.size()){
                auto a = pq.top();
                if(a-m <= start && start<=a){
                    pq.pop();
                }else{
                    count++;
                }
            }else{
                count++;
            }
            pq.push(end+m);
        }
    }
    cout << n - count << endl;
}
