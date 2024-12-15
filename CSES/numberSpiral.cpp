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
    for(int i=0; i<n; i++){
        
        ll colv = 0;
        ll rowv = 0;
        cin>>rowv>>colv;
        rowv--;
        colv--;
        ll maxs = max(rowv,colv);
        ll diag = (2*maxs)+1;
        ll val1 = pow((1+diag),2)/4;
        ll val2 = pow((diag-1),2)/4;
        // cout<<val1<<" "<<val2<<" "<<endl;
        ll ret = 0;
        if(rowv > colv){
            ll start = 0;
            bool even = rowv%2 == 0;
            if(even){
                start = val2 + (colv + 1);
            }else{
                start = val1 - (colv);
            }
            ret = start;
        }else if(colv>rowv){
            ll start = 0;
            bool even = colv%2 == 0;
            if(even){
                start = val1 - (rowv);
            }else{
                start = val2 + (rowv + 1);
            }
            ret = start;
        }else{
            
        }
        cout<<ret<<endl;
    }
}