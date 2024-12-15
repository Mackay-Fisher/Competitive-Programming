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
    ll a, b;
    cin >> a >> b;
    ld maxtime = 0;
    vector<pair<ld, ld> > asc;
    for (int i = 0; i < a; i++)
    {
        ld h, t;
        cin >> h >> t;
        maxtime += t;
        asc.push_back(make_pair(h, t));
    }
    vector<pair<ld, ld> > desc;
    ld maxdistanceDesc = 0;
    for (int i = 0; i < b; i++)
    {
        ld h, t;
        cin >> h >> t;
        maxdistanceDesc += h;
        desc.push_back(make_pair(h, t));
    }
    ld left = 0, right = maxtime;
    ld midtime  = 0;
    while (midtime != (right + left) / 2.0)
    {
        midtime = (right + left) / 2.0;
        ld evalAsc = 0;
        ld timeAsc = midtime;
        for (auto &a : asc)
        {
            if (timeAsc > a.second)
            {
                evalAsc += a.first;
                timeAsc -= a.second;
            }
            else
            {
                evalAsc += a.first * timeAsc / a.second;
                break;
            }
        }
        ld evalDesc = 0;
        ld timeDesc = midtime;
        for (auto &a : desc)
        {
            if (timeDesc > a.second)
            {
                evalDesc += a.first;
                timeDesc -= a.second;
            }
            else
            {
                evalDesc += a.first * timeDesc / a.second;
                break;
            }
        }
        evalDesc = maxdistanceDesc - evalDesc;
        // cout<<evalAsc<<" "<<evalDesc<<" "<<left<<" "<<right<<endl;
        if (evalAsc >= evalDesc)
        {
            right = midtime;
        }
        else{
            left = midtime;
        }
            
    }
    // cout << fixed << setprecision(6) << midtime << endl;
    // return 0;
}