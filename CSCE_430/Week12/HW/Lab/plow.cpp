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
int main()
{
    ll a,b;
    cin>>a>>b;
    ll jump = 0;
    ll backedges = b-(a-1);
    ll nodes = 1;
    ll edges = 1;
    ll sum = 1;
    for(int i=2; i<a; i++){
        nodes++;
        edges++;
        sum+=edges;
        ll minV = min(nodes-1,backedges);
        edges += minV;
        backedges -= minV;
    }
    cout<<sum<<endl;
}