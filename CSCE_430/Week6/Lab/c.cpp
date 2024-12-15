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
#include<set>
using namespace std;
int main()
{
    string s;
    vector<string> sVals;
    while (cin>>s)
    {
        sVals.push_back(s);
    }
    set<string> sortSet;
    for (int i = 0; i < sVals.size(); i++)
    {
        for (int j = 0; j < sVals.size(); j++){
            string temp = sVals[j];
            if (temp != sVals[i])
            {
                temp+=sVals[i];
                sortSet.insert(temp);
            }
            
        }
    }
    for(auto &a: sortSet){
        cout<<a<<endl;
    }
}
    
