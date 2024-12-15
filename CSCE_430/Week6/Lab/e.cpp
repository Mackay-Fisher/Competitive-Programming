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
    long long numChairs;
    cin >> numChairs;
    vector<pair<long long, long long> > chairs;
    for (int i = 0; i < numChairs; i++)
    {
        long long val;
        cin >> val;
        chairs.push_back(make_pair(i, val));
    }
    long long indexStart = 0;
    long long nextIndex = 0;
    long long size = chairs.size();
    while (size > 1)
    {
        nextIndex = (indexStart + chairs[indexStart].second -1 ) % size;
        chairs.erase(chairs.begin() + nextIndex);
        indexStart = nextIndex;
        size--;
        indexStart %= size;
    }
    cout<<chairs[0].first + 1<<endl;
}