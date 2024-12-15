// There is a set of positive integeres S
// They are uniequye if they do nto have teh smae subsets
// They 
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    long long testcases;
    
    cin >> testcases;
    for (int k = 0; k < testcases; k++)
    {
        long long numValues;
        unordered_map<long long, long long> SetSumMap;
        vector<long long> ValueMaps;
        set<long long> VisitedSums;
        cin >> numValues;
        cout << "Case #" << (k + 1) << ":" << endl;
        for (long long i = 0; i < numValues; i++)
        {
            long long val;
            cin >> val;
            ValueMaps.push_back(val);
        }
        for (int i = 0; i < (1 << 20); i++)
        {
            long long sum = 0;
            for (long long j = 0; j < 20; ++j)
            {
                if (i & (1 << j))
                {
                    sum += ValueMaps[j];
                }
            }

            if (SetSumMap.find(sum) != SetSumMap.end())
            {

                for (long long j = 0; j < 20; ++j)
                {
                    if (SetSumMap[sum] & (1 << j))
                    {
                        cout << ValueMaps[j] << " ";
                    }
                }
                cout << endl;
                for (long long j = 0; j < 20; ++j)
                {
                    if (i & (1 << j))
                    {
                        cout << ValueMaps[j] << " ";
                    }
                }
                cout << endl;
                break;
            }
            else
            {
                SetSumMap[sum] = i;
            }
        }
    }
}