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
using namespace std;
int main()
{
    long long q, m, s, l;
    cin >> q >> m >> s >> l;
    long long timeForS = 0;
    long long timeForQ = l / m * q;
    long long remainingVal = l % m;
    // cout<<timeForQ<<"  "<<remainingVal<<endl;
    // This is beacuse they are both just
    if (remainingVal == 0)
    {
        if (s == 0)
        {
            cout << timeForQ << endl;
            return 0;
        }
        else
        {
            timeForS = s / m + s%m;
        }
        cout << timeForQ + timeForS << endl;
        return 0;
    }
    timeForQ += q;
    // cout<<timeForQ<<"  "<<remainingVal<<endl;
    // if we do have remianign long tasks we need to then have to take as many long tem values out as possible
    long long openMachines = m - remainingVal;
    // This is ebacuse we are already required to use q time frams for the longer tasks;
    s -= openMachines * q;
    // cout<<s<<endl;
    if (s > 0)
    {
        timeForS += s / m + s%m;

    }
    cout << timeForQ + timeForS << endl;
    return 0;
}