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
vector<ll> distNode(160001, INT32_MAX);
ll djakstarts(unordered_map<ll, vector<pair<ll, ll>>> &cannonG, ll startCannon, ll endCannon)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> graphq;
    distNode[startCannon] = 1;
    graphq.push(make_pair(1, startCannon));
    // set debug staments of not
    bool debug = false;
    while (!graphq.empty())
    {
        ll curtVert = graphq.top().second;
        if (debug)
        {
            cout << "Current vertex: " << curtVert << endl;
        }
        graphq.pop();
        if (curtVert == endCannon)
        {
            break;
        }
        for (auto vect : cannonG[curtVert])
        {
            ll nextVert = vect.first;
            ll w = vect.second;
            if (debug)
            {
                cout << "Next vertex: " << nextVert << " Weight: " << w << endl;
            }
            if (distNode[curtVert] + w < distNode[nextVert])
            {
                distNode[nextVert] = distNode[curtVert] + w;
                graphq.push({distNode[nextVert], nextVert});
            }
        }
    }
    return distNode[endCannon];
}

int main()
{
    ll a, b;
    cin >> a >> b;
    vector<vector<char>> board(a, vector<char>(b));

    vector<ll> exits;
    unordered_map<ll, vector<pair<ll, ll>>> gmap;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (board[i][j] == 'c' || board[i][j] == 'D')
            {
                if (i == 0 || j == 0 || i == a - 1 || j == b - 1)
                {
                    exits.push_back(i * b + j);
                }
                else
                {
                    if (i > 0)
                    {
                        if (board[i - 1][j] == 'c' || board[i - 1][j] == 'D')
                        {
                            if (board[i - 1][j] == 'c')
                            {
                                gmap[i * b + j].push_back({(i - 1) * b + j, 1});
                            }
                            else
                            {
                                gmap[i * b + j].push_back({(i - 1) * b + j, 0});
                            }
                        }
                    }
                    if (i < a - 1)
                    {
                        if (board[i + 1][j] == 'c' || board[i + 1][j] == 'D')
                        {
                            if (board[i + 1][j] == 'c')
                            {
                                gmap[i * b + j].push_back({(i + 1) * b + j, 1});
                            }
                            else
                            {
                                gmap[i * b + j].push_back({(i + 1) * b + j, 0});
                            }
                        }
                    }
                    if (j > 0)
                    {
                        if (board[i][j - 1] == 'c' || board[i][j - 1] == 'D')
                        {
                            if (board[i][j - 1] == 'c')
                            {
                                gmap[i * b + j].push_back({i * b + (j - 1), 1});
                            }
                            else
                            {
                                gmap[i * b + j].push_back({i * b + (j - 1), 0});
                            }
                        }
                    }
                    if (j < b - 1)
                    {
                        if (board[i][j + 1] == 'c' || board[i][j + 1] == 'D')
                        {

                            if (board[i][j + 1] == 'c')
                            {
                                gmap[i * b + j].push_back({i * b + (j + 1), 1});
                            }
                            else
                            {

                                gmap[i * b + j].push_back({i * b + (j + 1), 0});
                            }
                        }
                    }
                }
            }
        }
    }

    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    ll start = x * b + y;
    ll minv = INT32_MAX;
    for (auto ex : exits)
    {
        minv = min(djakstarts(gmap, start, ex), minv);
    }

    cout << minv << endl;
}