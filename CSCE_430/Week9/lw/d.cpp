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
int main()
{
    
    while (true)
    {
        ll nx, ny;
        ld w;
        cin>>nx>>ny>>w;
        if (nx == 0 && ny == 0 && w == 0.0)
        {
            break;
        }
        vector<ld> xv(nx);
        vector<ld> yv(ny);
        for (int i = 0; i < nx; i++)
        {
            cin >> xv[i];
        }
        for (int i = 0; i < ny; i++)
        {
            cin >> yv[i];
        }
        sort(xv.begin(), xv.end());
        sort(yv.begin(), yv.end());
        bool validx = true;
        if (!(xv[0] - w/2 <= 0) || !(xv[nx - 1] + w/2 >= 75))
        {
            validx = false;
        }
        for (int i = 0; i < nx-1; i++)
        {
            // cout<<xv[i+1]-xv[i]<<" "<<w<<endl;
            if ((xv[i+1]-xv[i])>w)
            {
                validx = false;
            }
            
        }
        bool validy = true;
        if (!(yv[0] - w/2 <= 0) || !(yv[ny - 1] + w/2 >= 100))
        {
            validy = false;
        }
        for (int i = 0; i < ny-1; i++)
        {
            // cout<<yv[i+1]-yv[i]<<" "<<w<<endl;
            if ((yv[i+1]-yv[i])>w)
            {
                validy = false;
            }
            
        }
        if (validx && validy)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
}