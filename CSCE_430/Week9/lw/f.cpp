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
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
 
int main(){
    ll sizes, colors;
    cin>>sizes>>colors;
    vector<ll> siAr (sizes);
    vector<ll> colAr (colors);
    vector<ll> colorVal(colors);
    for (int i = 0; i < sizes; i++)
    {
        ll s;
        cin>>s;
        siAr.push_back(s);
    }
    sort(siAr.begin(),siAr.end());
    ll diff = 0;
    for (int i = 0; i < colors; i++)
    {
        ll c;
        cin>>c;
        auto lower = lower_bound(siAr.begin(),siAr.end(),c);
        diff += (*lower-c);
    }
    cout<<diff<<endl;
}