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
    ll house;
    while (cin >> house)
    {
        if (house == 0)
        {
            break;
        }
        vector<pair<ld, ld> > hvec;
        for (int i = 0; i < house; i++)
        {
            ld a, b;
            cin >> a >> b;
            hvec.push_back(make_pair(a, b));
        }
        ld right = INT32_MIN, left = INT32_MAX;
        for (auto &a : hvec)
        {
            right = max(right, a.first);
            left = min(a.first, left);
        }
        ld lm1, lm2;
        while (right >= left)
        {
            lm1 = left + (right - left) / 3;
            lm2 = right - (right - left) / 3;
            if (lm1 == lm2)
            {
               break;
            }
            ld timem1 = 0, timem2 = 0;
            for (auto &a : hvec)
            {
                
                auto t1 = sqrt(pow(a.first - lm1, 2) + pow(a.second, 2));
                auto t2 = sqrt(pow(a.first - lm2, 2) + pow(a.second, 2));
                timem1 = max(timem1, t1);
                timem2 = max(timem2, t2);
            }
            // cout << lm1 << " " << timem1 << " " << lm2 << " " << timem2 << endl;

            if (timem1 < timem2)
            {
                right = lm2;
            }
            else
            {
                left = lm1;
            }
        }
        ld finalx = (right+left)/2;
        ld finaltime = 0;
        for (auto &a : hvec)
        {
            auto fin = sqrt(pow(a.first - finalx, 2) + pow(a.second, 2));
            finaltime = max(finaltime, fin);
        }
        cout<<finalx<<" "<<finaltime<<endl;
    }
}

