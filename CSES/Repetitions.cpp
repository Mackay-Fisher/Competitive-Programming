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
    string n;
    cin>>n;
    char lead = 'Z';
    ll maxs = 0;
    ll cur = 0;
    for(int i=0; i<n.size(); i++){
        char nc = n[i];
        if(nc!=lead){
            maxs = max(maxs,cur);
            cur = 1;
            lead = nc;
        }else{
            cur++;
        }
    }
    maxs = max(maxs,cur);
    cout<<maxs<<endl;
}