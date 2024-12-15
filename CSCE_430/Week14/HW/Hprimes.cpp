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
vector<ll> allprimes;
vector<ll> allPrimeCombinations;
vector<ll> HTotal;
vector<bool> visited(1000001 + 3, true);
vector<bool> prime(1000001 + 3, true);
void Hprimes()
{
    for (int i = 5; i <= 1000001/5; i += 4)
    {
        HTotal.push_back(i);
    }
}
void computerPrimes()
{
    Hprimes();
    for (int i = 0; i < HTotal.size(); i++)
    {
        if (prime[HTotal[i]])
        {
            for (int j = i; HTotal[i] * HTotal[j] <= 1000001/5; j++)
            {
                prime[HTotal[i] * HTotal[j]] = false;
            }
        }
    }
    for (int i = 0; i < HTotal.size(); i++){
        if(prime[HTotal[i]]){
            allprimes.push_back(HTotal[i]);
        }
    }
}

void computeCombinations()
{
    for (int i = 0; i < allprimes.size(); i++)
    {
        for (int j = i; j < allprimes.size(); j++)
        {
            ll mult = allprimes[i] * allprimes[j];
            if (mult > 1000001)
            {
                continue;
            }
            else
            {
                if (visited[mult])
                {
                    visited[mult] = false;
                    allPrimeCombinations.push_back(mult);
                }
            }
        }
    }
}

void runP(ll val)
{
    ll count = 0;
    auto i = lower_bound(allPrimeCombinations.begin(), allPrimeCombinations.end(), val + 1);
    ll index = i - allPrimeCombinations.begin();
    cout << val << " " << index << endl;
}
int main()
{
    ll a;
    computerPrimes();
    computeCombinations();
    sort(allPrimeCombinations.begin(), allPrimeCombinations.end());
    while (cin >> a)
    {
        if (a != 0)
        {
            runP(a);
        }
    }
}