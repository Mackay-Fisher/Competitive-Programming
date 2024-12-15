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
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
class CustomDJ {
    private:

    public:
    vector<int> p;
    vector<int> maxH;
    //This will recursivley find the value of teh base of the set
    int find(int x){
        if(p[x]==x) return x;
        //Path compression to set the parent of teh current set to the base
        p[x]=find(p[x]);
        return p[x];
    }
    //This will merge base on the value of the max height and then adjust the pointer of the parent to the higher value or just adjust
    void merge(int a,int b){
        int x,y;
        //We find teh sets associated with the values passed in to merge
        x = find(a);
        y = find(b);
        //If they are in teh same ste we do nothing
        if(x==y) return;
        //we pick to merge based into the larger set
        if(maxH[x]>maxH[y]){
            p[y] = x;
        }else if (maxH[x] < maxH[y]){
            p[x]=y;
        }else{
            p[x]=y;
            maxH[y]++;
        }
    }

    void makeSet(long long x)
    {
        if (p.find(x) == p.end())
        {
            MapSet[x].insert(x);
            p[x] = x;
            size[x] = 1;
            sum[x] = x;
        }
    }
};
