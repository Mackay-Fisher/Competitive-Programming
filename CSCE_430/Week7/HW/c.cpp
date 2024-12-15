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
typedef long long ll;

int main()
{
    // 2d nap sack
    ll testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        ll coins, tV;
        cin >> coins >> tV;
        vector<pair<ll, ll> > heldcoins;
        vector<vector<ll> > napsack(tV+1);
        for (int i = 0; i <=tV; i++)
        {
            vector< ll> napsackRow(tV+1,INT16_MAX);
            napsack[i]=napsackRow;

        }
        
        for (int i = 0; i < coins; i++)
        {
            ll x, y;
            cin >> x >> y;
            heldcoins.push_back(make_pair(x,y));
        }
        napsack[0][0] = 0;
        for (int i = 0; i <=tV; i++)
        {
            for (int j = 0; j <=tV; j++)
            {
                if(i==0 && j==0){
                    continue;
                }
                ll coins = INT16_MAX;
                for(auto &coin: heldcoins){
                    if(i-coin.first < 0){
                        continue;
                    }
                    if(j-coin.second < 0){
                        continue;
                    }
                    if (napsack[i-coin.first][j-coin.second]!=INT16_MAX)
                    {
                        coins = min(coins,napsack[i-coin.first][j-coin.second]);
                    }
                }
                if(coins != INT16_MAX){
                    coins+=1;
                }
                napsack[i][j] = coins;
            }
        }
        ll minCoin = INT16_MAX;
        for (int i = 0; i <=tV; i++)
        {
            for (int j = 0; j <=tV; j++)
            {
                if((i*i)+(j*j) == (tV*tV)){
                    if(napsack[i][j] != INT16_MAX){
                        minCoin = min(minCoin,napsack[i][j]);
                    }
                }
            }
        }
        if(minCoin == INT16_MAX){
            cout<<"not possible"<<endl;
        }else{
            cout<<minCoin<<endl;
        }
    }
}