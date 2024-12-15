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
#include <tuple>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    ll n;
    cin>>n;
    vector<ll> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    ll moves = 0;
    for(int i=1; i<n; i++){
        ll change = abs(min(ll(0), (nums[i] - nums[i-1])));
        nums[i] = nums[i] + change;
        moves+= change;
    }
    cout<<moves<<endl;
}