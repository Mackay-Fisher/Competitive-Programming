//N minions
//We have to match the possible values
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
bool canMerge(pair<long long,long long>& p1, pair<long long,long long>& p2){
    if (p1.second >= p2.first)
    {
        return true;
    }
    return false;
}

int main(){
    long long numVals;
    cin>>numVals;
    vector<pair<long long,long long> > tempeture;
    set<pair<long long,long long> > valsSet;
    long long numRooms = 0;
    for (long long i = 0; i < numVals; i++)
    {
        long long low,high;
        cin>>low>>high;
        tempeture.push_back(make_pair(low,high));
    }
    sort(tempeture.begin(),tempeture.end());
    auto currentSet = tempeture[0];
    numRooms++;
    for (long long i = 1; i < numVals; i++)
    {
        if (canMerge(currentSet,tempeture[i]))
        {
            currentSet.first = max(currentSet.first,tempeture[i].first);
            currentSet.second = min(currentSet.second,tempeture[i].second);
        }else{
            numRooms++;
            currentSet = tempeture[i];
        }
    }
    cout<<numRooms<<endl;
}