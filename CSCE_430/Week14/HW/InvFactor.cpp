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
    string s;
    cin>>s;
    if(s.length()<=18){
        ll val = stoll(s);
        ll prod = 1;
        for(int i=1; i<26; i++){
            prod = prod * i;
            if(prod == val){
                cout<<i<<endl;
                return 0;
            }
        }
    }else{
        ld etsimate = s.length();
        ld sum = 0;
        for(int i=1; i<1000000; i++){
            sum += log10(i);
            if(sum > etsimate){
                cout<<i-1<<endl;
                return 0;
            }
        }
    }

}
