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
    ll modV = 1e9 + 7;
    ll num, length;
    cin >> num >> length;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<ll> timeSolv(num, 0);
    timeSolv[0] = d;
    // from kattis we have that next time ti = ((At_i-1 + B) mod c) + 1
    for (int i = 1; i < num; i++)
    {
        timeSolv[i] = ((a * timeSolv[i - 1] + b) % c) + 1;
    }
    ll timeTotal = 0;
    ll penalty = 0;
    ll index = 0;
    sort(timeSolv.begin(), timeSolv.end());
    for (int i = 0; i < num; i++)
    {
        if (timeTotal + timeSolv[i] > length)
        {
            index = i;
            break;
        }
        else
        {
            timeTotal += timeSolv[i];
            penalty = (penalty + timeTotal) % modV;
        }
    }
    if(index){
        cout<<index<<" "<<penalty<<endl;
    }else{
        cout << num << " " << penalty;
    }
}