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
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ll h, w;
    cin >> h >> w;
    vector<vector<ll> > ringsArr(h, vector<ll>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char a;
            cin >> a;
            if (a == 'T')
            {
                ringsArr[i][j] = 1;
            }
            else
            {
                ringsArr[i][j] = 0;
            }
        }
    }
    ll traversals = max(h, w) / 2;
    ll index = 1;
    ll rings = 0;
    while (traversals)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (i > 0 && j > 0 && i < h - 1 && j < w - 1)
                {
                    if (ringsArr[i - 1][j] >= index && ringsArr[i + 1][j] >= index && ringsArr[i][j + 1] >= index && ringsArr[i][j - 1] >= index)
                    {
                        ringsArr[i][j]++;
                        rings = max(rings, ringsArr[i][j]);
                    }
                }
            }
        }
        index++;
        traversals--;
    }
    bool extraSpcae = rings >= 10;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (ringsArr[i][j] > 0)
            {
                bool twoDim = ringsArr[i][j] / 10 >= 1;
                if (twoDim)
                {
                    cout << "." << ringsArr[i][j];
                }
                else
                {
                    if (extraSpcae)
                    {
                        cout << ".." << ringsArr[i][j];
                    }
                    else
                    {
                        cout << "." << ringsArr[i][j];
                    }
                }
            }
            else
            {
                if (extraSpcae)
                {
                    cout << "...";
                }
                else
                {
                    cout << "..";
                }
            }
        }
        cout << endl;
    }
}