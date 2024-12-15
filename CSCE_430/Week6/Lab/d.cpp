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
using namespace std;
int main()
{
    long long num;
    cin >> num;
    vector<long long> numsP;
    map<long long, long long> map;
    set<int> testVals;

    for (int i = 0; i < num; i++)
    {
        long long c;
        cin >> c;
        numsP.push_back(c);
    }
    sort(numsP.begin(), numsP.end(), greater<long long>());
    long long minval = numsP[0];
    long long hmax = num;
    for (int i = num - 1; i >= 0; i--)
    {
        if (numsP[num - i - 1] < num - i)
        {
            cout << num - i - 1;
            return 0;
        }
    }
    cout<<num;
    return 0;
}