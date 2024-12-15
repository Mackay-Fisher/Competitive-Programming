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
    long long n;
    cin >> n;
    vector<long long> bags;
    unordered_map<long long, long long> mbag;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        bags.push_back(a);
        mbag[a]++;
    }
    long long maxFrequency = 0;
    for (auto &key : mbag)
    {
        maxFrequency = max(maxFrequency, key.second);
    }
    cout << maxFrequency << endl;
    while (n) {
        bool first = true;
        if (first)
        {
            /* code */
        }
        
        for (auto &key : mbag)
        {
            cout<< key.first;
        }
        
        bool first = true;
        for (dit it = bags.begin(); it != bags.end(); ++it) {
            if (first) first = false;
            else putchar(' ');

            if (it->second > 0) {
                printf("%d", it->first);
                it->second--;
                n--;
            }

            if (it->second == 0) remove.insert(it->first);
        }
        putchar('\n');
        for (sit it = remove.begin(); it != remove.end(); ++it) bags.erase(*it);
        remove.clear();
    }
    vector<pair<long long,long long> > retBags(maxFrequency,make_pair(-1, -1));
    long long index = 0;
    for (int i = 0; i < n; i++)
    {
        if (i<maxFrequency)
        {
            retBags[i].first = bags[i];
        }else{
            retBags[index].second = bags[i];
            index++;
        }
    }
    for (int i = 0; i < maxFrequency; i++)
    {
        cout<<retBags[i].first<<" "<<retBags[i].second<<endl;
    }

    
    
    
}