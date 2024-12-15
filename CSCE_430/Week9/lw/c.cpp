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
    while (true)
    {
        ll a;
        cin >> a;
        if (a == 0)
        {
            break;
        }
        cin.ignore();
        vector<int> hassh(a);
        // unordered_map<ll,
        vector<string> lin(a);
        set<string> met;
        for (int i = 0; i < a; i++)
        {
            string s;
            getline(cin, s);
            met.insert(s);
            stringstream ss(s);
            lin[i] = s;
            string word;
            int n = 0;
            for (char &c : s)
            {
                int a = c;
                n ^= a;
            }
            hassh[i] = n;
        }
        ll coll = 0;
        ll f = 1;
    
        for (int i = 0; i < a; i++)
        {
            for (int j = i + 1; j < a; j++)
            {
                if (hassh[i] == hassh[j])
                {
                    if (lin[i] != lin[j])
                    {
                        coll++;
                    }
                }
            }
        }
        cout<<met.size()<<" "<<coll<<endl;
    }
}