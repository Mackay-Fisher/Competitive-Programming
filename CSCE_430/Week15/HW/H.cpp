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
#include <math.h> 
using namespace std;
typedef long long ll;
typedef long double ld;
bool isTriangle(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
    set<pair<ll,ll>> noDups;
    noDups.insert(a);
    noDups.insert(b);
    noDups.insert(c);
    ld area = a.first * (b.second- c.second) + b.first *(c.second-a.second) + c.first * (a.second-b.second);
    return area != 0 && noDups.size()==3;
}
void runP(){
    vector<pair<ll,ll>> triangle;
    for(int i=0; i<3; i++){
        ll a,b;
        cin>>a>>b;
        triangle.push_back({a,b});
    }
    if(isTriangle(triangle[0],triangle[1],triangle[2])){
        vector<ld> sides;
        ld ab = sqrt((pow(triangle[1].first - triangle[0].first,2) + pow(triangle[1].second- triangle[0].second,2)));
        sides.push_back(pow(ab,2));
        ld bc = sqrt((pow(triangle[1].first - triangle[2].first,2) + pow(triangle[1].second- triangle[2].second,2)));
        sides.push_back(pow(bc,2));
        ld ac = sqrt((pow(triangle[0].first - triangle[2].first,2) + pow(triangle[0].second- triangle[2].second,2)));
        sides.push_back(pow(ac,2));
        sort(sides.begin(),sides.end());
        ld a2 = sides[0];
        ld b2 = sides[1];
        ld c2 = sides[2];
        set<ld> sidesV;
        sidesV.insert(a2);
        sidesV.insert(b2);
        sidesV.insert(c2);
        if(sidesV.size()==3){
            cout<<"scalene ";
        }else{
            cout<<"isosceles ";
        }
        ld check = a2 + b2;
        if(abs(check - c2)<0.0002){
            cout<<"right";
        }
        else if(check < c2){
            cout<<"obtuse";
        }else{
            cout<<"acute";
        }
        cout<<" triangle"<<endl;
         
    }else{
        cout<<"not a triangle"<<endl;
    }
}
int main(){
    ll n;
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Case #"<<(i+1)<<": ";
        runP();
    }
}