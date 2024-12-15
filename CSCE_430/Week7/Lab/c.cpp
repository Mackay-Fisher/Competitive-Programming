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
    stack<long long> cA;
    vector<long long> cards;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        cards.push_back(a);
    }
    reverse(cards.begin(), cards.end());
    for (int i = 0; i < n; i++)
    {
        cA.push(cards[i]);
    }
    stack<long long> cB;
    while (!cA.empty() || !cB.empty())
    {
        bool changed = false;
        while (!cA.empty())
        {
            long long a = cA.top();
            cA.pop();
            if (!cA.empty())
            {
                long long b = cA.top();
                cA.pop();
                if ((a + b) % 2 != 0)
                {
                    cB.push(a);
                    cA.push(b);
                }
                if((a + b) % 2==0){
                    changed = true;
                }
            }
            else
            {
                cB.push(a);
                break;
            }
        }
        while (!cB.empty())
        {
            long long a = cB.top();
            cB.pop();
            if (!cB.empty())
            {
                long long b = cB.top();
                cB.pop();
                if ((a + b) % 2 != 0)
                {
                    cA.push(a);
                    cB.push(b);
                }
                if((a + b) % 2==0){
                    changed = true;
                }
            }
            else
            {
                cA.push(a);
                break;
            }
        }
        if(!changed){
            break;
        }
    }

    cout << cA.size()+cB.size() << endl;
}