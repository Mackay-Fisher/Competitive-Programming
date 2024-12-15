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
#include <algorithm>
#include <set>
#include <map>
#include <tuple>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
ll length(ll val){
    ll size = 0;
    while (val)
    {
     ++size; 
     val /= 10;
    }
    return size;
}
ll helpme(ll val){
    ll index = 0;
    set<ll> nums;
    nums.insert(val);
    while(true){
        ll local = length(val);
        if(nums.count(local)){
            return nums.size()+1;
        }
        nums.insert(local);
        val = local;
    }
}
int main(){
    string s;
    ll maxv = 0;
    ll prev = 0;
    ll index = 0;
    while (cin>>s)
    {
        if(s=="END"){
            break;
        }
        if(s=="1"){
            cout<<1<<endl;
        }else{
            cout<<helpme(s.length())<<endl;
        }
    }
}