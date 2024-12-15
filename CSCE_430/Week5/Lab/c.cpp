#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include<algorithm>
using namespace std;
int main()
{
    long long length, distance, birds;
    cin >> length >> distance >> birds;
    vector<long long> positions;
    long long right = 6;
    long long left = length - 6;
    for (int i = 0; i < birds; i++)
    {
        long long pos;
        cin >> pos;
        positions.push_back(pos);
    }
    long long count;
    if (birds == 0)
    {
        cout << ((length - 12) / distance) + 1 << endl;
    }
    else
    {
        sort(positions.begin(), positions.end());
        count += (positions[0] -6) / distance;
        for (int i = 0; i < positions.size()-1; i++)
        {
            long long gap = positions[i+1]-positions[i];
            int a = gap / distance -1;
            count += a;
        }
        count += (length - positions[positions.size()-1] - 6) / distance;
        cout << count << endl;
        
    }
    
}
