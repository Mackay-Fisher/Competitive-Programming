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
    vector<ll> pop;
    ll dead = 0;
    for(int i=0; i<n; i++){
        ll a;
        cin>>a;
        pop.push_back(a);
    }
    for(int i=n-1; i>0; i--){
        if(pop[i] <= pop[i-1]){
            if(pop[i-1]-pop[i] == pop[i-1]){
                cout<<1<<endl;
                return 0;
            }
            dead += pop[i-1]-pop[i] +1;
            pop[i-1] = pop[i]-1;
        }
    }
    cout<<dead<<endl;
}