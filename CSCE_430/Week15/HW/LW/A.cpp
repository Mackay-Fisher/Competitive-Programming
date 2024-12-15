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
int Perfect(ll v){
    ll sum = 0;
    set<ll> factors;
    for(int i=1; i<sqrt(v)+1; i++){
        if(v%i==0){
            factors.insert(i);
            factors.insert(v/i);
        }
    }
    for(auto &a : factors){
        sum+= a;
    }
    sum-=v;
    if(sum==v){
        return 1;
    }
    if(abs(sum-v)<=2){
        return 2;
    }else{
        return 3;
    }
}
int main(){
    ll n;
    while(cin>>n){
        ll val = Perfect(n);
        if(val == 1){
            cout<<n<<" perfect"<<endl;
        }
        if(val == 2){
            cout<<n<<" almost perfect"<<endl;
        }
        if(val == 3){
            cout<<n<<" not perfect"<<endl;
        }
    }
}