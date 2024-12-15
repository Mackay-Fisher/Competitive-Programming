// Given values n and k where n is the number of stops k is the current carrying capcity of the mail truck
// Then give route positive or nregtaive when the valeu is at zero reset the carrying capcity
// We need to itterate from furthest diatsnce back to teh the satring disdtance eahc time we can change the capaicty on the way back offlaoding asmuch as we can
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> negativeStops;
    vector<long long> posotiveStops;
    for (int i = 0; i < n; i++)
    {
        long long d, p;
        cin >> d >> p;
        if (d > 0)
        {
            for (long long i = 0; i < p; i++)
            {
                posotiveStops.push_back(d);
            }
        }
        else
        {
            for (long long i = 0; i < p; i++)
            {
                negativeStops.push_back(d);
            }
        }
    }
    // Sorted greater to least then sorted least to greatest for negative thatw ay we cna get longest path for both.
    sort(posotiveStops.begin(), posotiveStops.end());
    sort(negativeStops.begin(), negativeStops.end(), greater<int>());
    // for(auto i : posotiveStops)
    // {
    //     cout << i << endl;
    // }
    // for(auto i : negativeStops)
    // {
    //     cout << i<< endl;
    // }
    long long distance = 0;
    long long capaicty = 0;
    for (int i = posotiveStops.size() - 1; i >= 0; i--)
    {
        if (capaicty == 0)
        {
            capaicty = k;
            distance += 2 * posotiveStops[i];
        }
        capaicty--;
    }
    capaicty = 0;
    for (int i = negativeStops.size()-1; i >=0; i--)
    {
        if (capaicty == 0)
        {
            capaicty = k;
            distance += 2 * -1 * negativeStops[i];
        }
        capaicty--;
    }

    cout << distance << endl;

    return 0;
}