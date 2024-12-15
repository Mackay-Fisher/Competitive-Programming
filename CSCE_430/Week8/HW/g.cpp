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
    ll n;
    cin>>n;
    vector<ld> cards(n);
    for (int i = 0; i<n; i++)
    {
        cin>>cards[i];
    }
    vector<ld> reversecards = cards;
    reverse(reversecards.begin(),reversecards.end());
    vector<ld> raverage(n);
    raverage[0] = reversecards[0];
    ld maxR = reversecards[0];
    for (int i = 1; i < cards.size(); i++)
    {
        raverage[i] = (raverage[i-1] * i + reversecards[i])/(i+1);
        maxR = max(maxR,raverage[i]);
    }
    vector<ld> laverage(n);
    laverage[0] = cards[0];
    ld maxL = cards[0];
    for (int i = 1; i < cards.size(); i++)
    {
        laverage[i] = (laverage[i-1] * i + cards[i])/(i+1);
        maxL = max(maxL,laverage[i]);
    }
    ld totalMax = max(maxR,maxL);
    if(totalMax < 0){
        totalMax = 0;
    }
    cout<<fixed<<setprecision(9)<<totalMax<<endl; 
}