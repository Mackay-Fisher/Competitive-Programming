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
void run(){
    string a,b;
    cin>>a>>b;
    swap(a[0],b[0]);
    cout<<a<<" "<<b<<endl;
}
int main(){
    ll s;
    cin>>s;
    while(s){
        run();
        s--;
    }
}