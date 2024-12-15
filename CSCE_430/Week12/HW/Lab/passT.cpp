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
#include <algorithm>
#include <set>
#include <map>
#include <tuple>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
const vector<pair<ll, ll>> directions{{-1, 1}, {0, 1}, {1, 1}};
int main()
{
    ll r, c, n;
    cin >> r >> c >> n;
    vector<vector<vector<ll>>> dp(r, vector<vector<ll>>(c, vector<ll>(n + 1, 1e18)));
    vector<vector<ll>> board(r, vector<ll>(c));
    vector<vector<bool>> passes(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ll a;
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
            {
                continue;
            }

            if ((board[i + 1][j] > board[i][j] && (board[i + 1][j] > 0)) && (board[i - 1][j] > board[i][j] && (board[i - 1][j] > 0)) && (board[i][j - 1] < board[i][j] && (board[i][j - 1] > 0)) && (board[i][j + 1] < board[i][j] && (board[i][j + 1] > 0)))
            {
                passes[i][j] = true;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        if (board[i][0] != -1)
        {
            dp[i][0][0] = board[i][0];
        }
    }
    ll minVal = 1e18;
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
            for (int z = 0; z <= n; z++)
            {
                if (dp[i][j][z] == 1e18){
                    continue;
                }
                if (j == c - 1)
                {
                    if (z == n)
                    {
                        minVal = min(minVal, dp[i][j][n]);
                    }
                }
                for (auto dir : directions)
                {
                    ll x = i + dir.first;
                    ll y = j + dir.second;
                    ll q = z;
                    if (x >= 0 && x < r && y >= 0 && y < c)
                    {
                        if (board[x][y] != -1)
                        {
                            if (passes[x][y])
                            {
                                q++;
                            }
                            if(q>n){
                                continue;
                            }
                            dp[x][y][q] = min(dp[x][y][q], dp[i][j][z] + board[x][y]);
                        }
                    }
                }
            }
        }
    }
    for(int i =0; i<r; i++){
        minVal = min(minVal, dp[i][c-1][n]);
    }
    if (minVal == 1e18)
    {
        cout << "impossible" << endl;
    }
    else
    {
        cout << minVal << endl;
    }
}