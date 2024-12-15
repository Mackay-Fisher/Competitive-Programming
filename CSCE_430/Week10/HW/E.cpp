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
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<vector<ll>> dp(n, vector<ll>(m, INT32_MAX));
    pq.push({0, {0, 0}});
    dp[0][0]=0;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ll diff = top.first, x = top.second.first, y = top.second.second;
        if (dp[x][y] != diff)
        {
            continue;
        }
        dp[x][y] = diff;
        if (x >= 1)
        {
            ll newdiff = max((ll)diff, (grid[x - 1][y] - grid[x][y]));
            if (newdiff < dp[x - 1][y])
            {
                pq.push({newdiff, {x - 1, y}});
                dp[x - 1][y] = newdiff;
            }
        }
        if (x < n - 1)
        {
            ll newdiff = max((ll)diff, (grid[x + 1][y] - grid[x][y]));
            if (newdiff < dp[x + 1][y])
            {
                pq.push({newdiff, {x + 1, y}});
                dp[x + 1][y] = newdiff;
            }
        }
        if (y >= 1)
        {
            ll newdiff = max((ll)diff, (grid[x][y - 1] - grid[x][y]));
            if (newdiff < dp[x][y-1])
            {
                pq.push({newdiff, {x, y-1}});
                dp[x][y-1] = newdiff;
            }

        }
        if (y < m - 1)
        {
            ll newdiff = max((ll)diff, (grid[x][y + 1] - grid[x][y]));
            if (newdiff < dp[x][y+1])
            {
                pq.push({newdiff, {x, y+1}});
                dp[x][y+1] = newdiff;
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}