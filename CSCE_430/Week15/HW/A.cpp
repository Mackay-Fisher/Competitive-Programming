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
pair<pair<ld, ld>, bool> interSectionP(pair<pair<ld, ld>, pair<ld, ld>> p1, pair<pair<ld, ld>, pair<ld, ld>> p2)
{
    // I looked up how to calcualte the intersection points Used this video: https://www.youtube.com/watch?app=desktop&v=bvlIYX9cgls
    ld x1 = p1.first.first, x2 = p1.second.first, x3 = p2.first.first, x4 = p2.second.first;
    ld y1 = p1.first.second, y2 = p1.second.second, y3 = p2.first.second, y4 = p2.second.second;
    ld denom = ((x4 - x3) * (y2 - y1)) - ((y4 - y3) * (x2 - x1));
    ld aVal = ((x4 - x3) * (y3 - y1)) - ((y4 - y3) * (x3 - x1));
    ld cVal = ((x2 - x1) * (y3 - y1)) - ((y2 - y1) * (x3 - x1));
    ld alpha = aVal / denom;
    ld beta = cVal / denom;
    if ((alpha >= 0 && alpha <= 1) && (beta >= 0 && beta <= 1))
    {
        ld x0 = x1 + alpha * (x2 - x1);
        ld y0 = y1 + alpha * (y2 - y1);
        return {{x0, y0}, true};
    }

    return {{0, 0}, false};
}
bool diffIntersection(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c)
{
    ld x12 = abs(a.first - b.first), y12 = abs(a.second - b.second);
    ld x23 = abs(b.first - c.first), y23 = abs(b.second - c.second);
    ld x13 = abs(a.first - c.first), y13 = abs(a.second - c.second);
    bool diff12 = (x12 > 0.0001) || (y12 > 0.0001);
    bool diff23 = (x23 > 0.0001) || (y23 > 0.0001);
    bool diff13 = (x13 > 0.0001) || (y13 > 0.0001);
    return diff12 && diff13 && diff23;
}

bool isTraingle(pair<pair<ld, ld>, pair<ld, ld>> p1, pair<pair<ld, ld>, pair<ld, ld>> p2, pair<pair<ld, ld>, pair<ld, ld>> p3)
{
    auto int1 = interSectionP(p1, p2);
    auto int2 = interSectionP(p2, p3);
    auto int3 = interSectionP(p1, p3);

    if (!int1.second || !int2.second || !int3.second)
    {
        return false;
    }

    pair<ld, ld> ip1 = int1.first;
    pair<ld, ld> ip2 = int2.first;
    pair<ld, ld> ip3 = int3.first;

    if(diffIntersection(ip1, ip2, ip3)){
        return true;
    }else{
        return false;
    }

    return false;
}

void runP(ll n)
{
    vector<pair<pair<ld, ld>, pair<ld, ld>>> lineVals;
    ll tCount = 0;
    for (int i = 0; i < n; i++)
    {
        ld x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lineVals.push_back({{x1, y1}, {x2, y2}});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int q = j + 1; q < n; q++)
            {
                if (isTraingle(lineVals[i], lineVals[j], lineVals[q]))
                {
                    tCount++;
                }
            }
        }
    }
    cout << tCount << endl;
}
int main()
{
    ll n;
    while (cin >> n)
    {
        if (n != 0)
        {
            runP(n);
        }
    }
}