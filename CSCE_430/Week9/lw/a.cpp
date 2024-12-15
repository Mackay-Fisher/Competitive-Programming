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
    ll n;
    cin >> n;
    ll lim = round(cbrt(n));
    set<ll> heldNums;
    ll maxval = 0;
    unordered_map<ll, pair<ll, ll> > xymap;
    for (int i = 1; i <=lim; i++)
    {
        for (int j = 1; j <=lim; j++)
        {
            ll num = pow(i, 3) + pow(j, 3);
            if (heldNums.find(num) != heldNums.end())
            {
                auto pair = xymap[num];
                // cout << i << " " << pair.first << " " << j << " " << pair.second << endl;
                if (i != pair.first && j != pair.second&&i!=pair.second&&j!=pair.first)
                {
                    if (num <= n)
                    {
                        maxval = max(maxval, num);
                    }
                }
            }
            else
            {
                heldNums.insert(num);
                xymap[num] = make_pair(i, j);
            }
        }
    }
    if(maxval!=0){
        cout<<maxval<<endl;
    }else{
        cout<<"none"<<endl;
    }
}