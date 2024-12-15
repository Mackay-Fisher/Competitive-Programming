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
using namespace std;
int main()
{
    unordered_map<string, long long> DefMap;
    unordered_map<long long, string> DefVal;
    string s;
    while (cin >> s)
    {
        if (s == "clear")
        {
            DefMap.clear();
            DefVal.clear();
        }
        if (s == "def")
        {
            string val;
            long long num;
            cin >> val >> num;
            if (DefMap.find(val) != DefMap.end())
            {
                long long tempval = DefMap[val];
                DefVal.erase(tempval);
                DefMap.erase(val);
            }
            DefMap[val] = num;
            DefVal[num] = val;
        }
        if (s == "calc")
        {
            string line;
            getline(cin, line);
            stringstream ss(line);
            string word;
            vector<string> lineArray;
            queue<string> Ops;
            queue<long long> vals;
            bool unkown = false;
            long long sum = 0;
            while (ss >> word)
            {
                if (word == "calc")
                {
                    continue;
                }

                if (word == "=")
                {
                    lineArray.push_back(word);
                    break;
                }

                if (word == "+" || word == "-")
                {
                    Ops.push(word);
                }
                else
                {
                    if (DefMap.find(word) == DefMap.end())
                    {
                        unkown = true;
                    }
                    else
                    {
                        vals.push(DefMap[word]);
                    }
                }
                lineArray.push_back(word);
            }
            if (!unkown)
            {
                long long localsum = vals.front();
                vals.pop();
                while (!Ops.empty())
                {
                    long long val1 = vals.front();
                    vals.pop();
                    if (Ops.front() == "+")
                    {
                        localsum += val1;
                    }
                    else
                    {
                        localsum -= val1;
                    }
                    Ops.pop();
                }
                sum = localsum;
            }
            if (DefVal.find(sum) == DefVal.end())
            {
                unkown = true;
            }
            if (!unkown)
            {
                for (auto &a : lineArray)
                {
                    cout << a << " ";
                }
                cout << DefVal[sum] << endl;
            }
            else
            {
                for (auto &a : lineArray)
                {
                    cout << a << " ";
                }
                cout << "unknown" << endl;
            }
        }
    }
}