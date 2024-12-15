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
void topSort(string v, unordered_map<string, vector<string>> &tmap, set<string> &visited, stack<string> &Stack){
    visited.insert(v);
    for (auto a : tmap[v])
    {
        if (!visited.count(a))
        {
            topSort(a, tmap, visited, Stack);
        }
    }
    Stack.push(v);
}

int main()
{
    ll n;
    cin >> n;
    unordered_map<string, vector<string>> tmap;
    for (int i = 0; i <= n; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        vector<string> words;
        int index = 0;
        string name;
        while (ss >> word)
        {
            if (index == 0)
            {
                word.pop_back();
                name = word;
            }
            else
            {
                tmap[word].push_back(name);
            }
            index++;
        }
    }
    // for(auto a: tmap){
    //     cout<<a.first<<": ";
    //     for(auto b: a.second){
    //         cout<<"-> "<<b<<" ";
    //     }
    //     cout<<endl;
    // }
    string startNode;
    cin>>startNode;
    set<string> vis;
    stack<string> st;
    topSort(startNode,tmap,vis,st);

    while (!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
}