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
#include <algorithm>
#include <set>
#include <map>
#include <tuple>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    string s;
    unordered_map<ll, ll> rankNum;
    rankNum[25] = 2;
    rankNum[24] = 2;
    rankNum[23] = 2;
    rankNum[22] = 2;
    rankNum[21] = 2;
    rankNum[20] = 3;
    rankNum[19] = 3;
    rankNum[18] = 3;
    rankNum[17] = 3;
    rankNum[16] = 3;
    rankNum[15] = 4;
    rankNum[14] = 4;
    rankNum[13] = 4;
    rankNum[12] = 4;
    rankNum[11] = 4;
    rankNum[10] = 5;
    rankNum[9] = 5;
    rankNum[8] = 5;
    rankNum[7] = 5;
    rankNum[6] = 5;
    rankNum[5] = 5;
    rankNum[4] = 5;
    rankNum[3] = 5;
    rankNum[2] = 5;
    rankNum[1] = 5;
    rankNum[0] = 5;

    cin >> s;

    ll rank = 25;
    ll starr = 0;
    ll winstreak = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // cout<<rank<<" "<<starr<<" "<<" "<<s[i]<<" "<<winstreak<<endl;
        if (s[i] == 'W')
        {
            winstreak++;
            if (winstreak >= 3 && rank > 5)
            {
                starr += 2;
            }
            else
            {
                starr++;
            }
        }
        else
        {
            if (rank <= 20)
            {
                starr--;
                if (starr < 0 && rank < 20)
                {
                    rank++;
                    starr = rankNum[rank]-1;
                }
                if(starr < 0 && rank == 20){
                    starr = 0;
                }
            }
            winstreak = 0;
        }


        if (rankNum[rank] < starr)
        {
            starr -= rankNum[rank];
            rank--;
            if (!rank)
            {
                cout << "Legend" << endl;
                return 0;
            }
        }
    }
    cout << rank << endl;
}