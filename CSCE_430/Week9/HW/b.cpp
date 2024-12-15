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
#include <fstream>
#include <functional>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <istream>
#include <iterator>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ll r, c;
    cin >> r >> c;
    vector<vector<ll> > board(r, vector<ll>(c));
    pair<ll, ll> start;
    pair<ll, ll> fire;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char a;
            cin >> a;
            if (a == '#')
            {
                board[i][j] = -1;
            }
            if (a == '.')
            {
                if (i == 0 || j == 0 || j == c - 1 || i == r - 1)
                {
                    board[i][j] = INT32_MAX;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
            if (a == 'J')
            {
                board[i][j] = 1;
                start = make_pair(i, j);
            }
            if (a == 'F')
            {
                board[i][j] = 2;
                fire = make_pair(i, j);
            }
        }
    }

    queue<pair<ll, ll> > q;
    q.push(start);
    vector<vector<ll> > playeboard(r, vector<ll>(c));
    set<pair<ll, ll> > winningNums;
    playeboard = board;
    while (!q.empty())
    {
        pair<ll, ll> cur = q.front();
        q.pop();
        ll x = cur.first;
        ll y = cur.second;
        if (x - 1 >= 0)
        {
            if (playeboard[x - 1][y] == 0)
            {
                playeboard[x - 1][y] = playeboard[x][y] + 1;
                q.push(make_pair(x - 1, y));
            }
            if (playeboard[x - 1][y] == INT32_MAX)
            {
                winningNums.insert(make_pair(x, y));
            }
        }
        if (x + 1 < r)
        {
            if (playeboard[x + 1][y] == 0)
            {
                playeboard[x + 1][y] = playeboard[x][y] + 1;
                q.push(make_pair(x + 1, y));
            }
            if (playeboard[x + 1][y] == INT32_MAX)
            {
                winningNums.insert(make_pair(x, y));
            }
        }
        if (y - 1 >= 0)
        {
            if (playeboard[x][y - 1] == 0)
            {
                playeboard[x][y - 1] = playeboard[x][y] + 1;
                q.push(make_pair(x, y - 1));
            }
            if (playeboard[x][y - 1] == INT32_MAX)
            {
                winningNums.insert(make_pair(x, y));
            }
        }
        if (y + 1 < c)
        {
            if (playeboard[x][y + 1] == 0)
            {
                playeboard[x][y + 1] = playeboard[x][y] + 1;
                q.push(make_pair(x, y + 1));
            }
            if (playeboard[x][y + 1] == INT32_MAX)
            {
                winningNums.insert(make_pair(x, y));
            }
        }
    }

    q.push(fire);
    vector<vector<ll> > fireboard(r, vector<ll>(c));
    set<pair<ll, ll> > fireNums;
    fireboard = board;
    while (!q.empty())
    {
        pair<ll, ll> cur = q.front();
        q.pop();
        ll x = cur.first;
        ll y = cur.second;
        if (x - 1 >= 0)
        {
            if (fireboard[x - 1][y] == 0)
            {
                fireboard[x - 1][y] = fireboard[x][y] + 1;
                q.push(make_pair(x - 1, y));
            }
            if (fireboard[x - 1][y] == INT32_MAX)
            {
                fireNums.insert(make_pair(x, y));
            }
        }
        if (x + 1 < r)
        {
            if (fireboard[x + 1][y] == 0)
            {
                fireboard[x + 1][y] = fireboard[x][y] + 1;
                q.push(make_pair(x + 1, y));
            }
            if (fireboard[x + 1][y] == INT32_MAX)
            {
                fireNums.insert(make_pair(x, y));
            }
        }
        if (y - 1 >= 0)
        {
            if (fireboard[x][y - 1] == 0)
            {
                fireboard[x][y - 1] = fireboard[x][y] + 1;
                q.push(make_pair(x, y - 1));
            }
            if (fireboard[x][y - 1] == INT32_MAX)
            {
                fireNums.insert(make_pair(x, y));
            }
        }
        if (y + 1 < c)
        {
            if (fireboard[x][y + 1] == 0)
            {
                fireboard[x][y + 1] = fireboard[x][y] + 1;
                q.push(make_pair(x, y + 1));
            }
            if (fireboard[x][y + 1] == INT32_MAX)
            {
                fireNums.insert(make_pair(x, y));
            }
        }
    }

    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout<<board[i][j];
    //     }
    //     cout<<endl;
    // }
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout<<fireboard[i][j];
    //     }
    //     cout<<endl;
    // }
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout<<playeboard[i][j];
    //     }
    //     cout<<endl;
    // }
    

    ll distance = INT32_MAX;
    for (auto &a : winningNums)
    {
        if (fireboard[a.first][a.second] > playeboard[a.first][a.second])
        {
            distance = min(distance, playeboard[a.first][a.second]);
        }
        
    }
    if(distance==INT32_MAX)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        cout<<distance+1<<endl;
    }
}