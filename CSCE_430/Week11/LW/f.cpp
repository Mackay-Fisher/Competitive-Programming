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
    unordered_map<string,ll> kat;
    unordered_map<string,ll> dom;
    set<string> resp;
    for(int i=0; i< n; i++){
        string s;
        cin>>s;
        dom[s]++;
        resp.insert(s);
    }
    for(int i=0; i< n; i++){
        string s;
        cin>>s;
        kat[s]++;
        resp.insert(s);
    }
    ll count=0;
    for(auto s:resp){
        count += min(kat[s],dom[s]);
    }
    cout<<count<<endl;
}