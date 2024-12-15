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
    ll d;
    cin>>d;

    for(int i=0; i<=d; i++){
        ll check = (d+pow(i,2));
        ld val = sqrt(check);
        ll n2 = ll(val);
        // cout<<n2<<" "<<i<<endl;
        if((pow(n2,2) - pow(i,2)) == d){
            cout<<i<<" "<<n2<<endl;
            return 0;
        }
    }
    cout<<"impossible"<<endl;
}