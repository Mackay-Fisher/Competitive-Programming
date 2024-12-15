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
    vector<int> vals(n+1,0);
    for(int i=0; i<n-1; i++){
        int a;
        cin>>a;
        vals[a] = 1;
    }
    for(int i=1; i<n+1; i++){
        if(!vals[i]){
            cout<<i;
        }
    }
}