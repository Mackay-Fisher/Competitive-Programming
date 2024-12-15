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
// ll valtime = 0;
// ll maxconnect = -1;
// void tarjans(unordered_map<string,vector<string>> &gmap, unordered_map<string,ll> &indexMap, string node, vector<ll> &desc, vector<ll> &lowlink, vector<bool> &onStack, stack<ll> &conStack){
//     ll no = indexMap[node];
//     ++valtime;
//     desc[no] = valtime;
//     lowlink[no] = valtime;
//     conStack.push(no);
//     onStack[no] = true;

//     for(auto &n : gmap[node]){
//         // cout<<n<<endl;
//         ll nn = indexMap[n];
//         if(desc[nn]==-1){
//             tarjans(gmap,indexMap,n,desc,lowlink,onStack,conStack);
//             lowlink[no] = min(lowlink[no],lowlink[nn]);
//         }else if(onStack[no]){
//             lowlink[no] = min(lowlink[no],desc[nn]);
//         }
//     }

//     ll index = 0;
//     ll size = 1;
//     if(lowlink[no]==desc[no]){
//         while (conStack.top()!= no)
//         {
//            index = conStack.top();
//            onStack[index] = false;
//            conStack.pop();
//            size++;
//         }
//         index = conStack.top();
//         maxconnect = max(maxconnect,size);
//         onStack[index] = false;
//         conStack.pop();
//     }

// }

// Gave up on tarjans now time to do korsojals

vector<string> order;
set<string> found;
vector<string> comp;
vector<vector<string>> comps;
void dfsFor(string v, unordered_map<string, vector<string>> &adj)
{
    found.insert(v);
    for (auto n : adj[v])
    {
        if (found.find(n) == found.end())
        {
            dfsFor(n, adj);
        }
    }
    order.push_back(v);
}

void dfsRev(string v, unordered_map<string, vector<string>> &reverse)
{
    found.insert(v);
    comp.push_back(v);
    for (auto n : reverse[v])
    {
        if (found.find(n) == found.end())
        {
            dfsRev(n, reverse);
        }
    }
}

int main()
{
    ll c;
    cin >> c;
    cin.ignore();
    vector<string> names;
    unordered_map<string, vector<string>> under;
    unordered_map<string, vector<string>> speaking;
    unordered_map<string, ll> indexMap;
    for (int i = 0; i < c; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        int index = 0;
        string name = "";
        vector<string> languages;
        while (ss >> word)
        {
            if (index == 0)
            {
                name = word;
                names.push_back(name);
            }
            else if (index == 1)
            {
                speaking[word].push_back(name);
                under[word].push_back(name);
            }
            else
            {
                under[word].push_back(name);
            }
            index++;
        }
    }
    unordered_map<string, vector<string>> adj;
    unordered_map<string, vector<string>> rev;
    for (auto p : speaking)
    {
        for (auto s : p.second)
        {
            for (auto un : under[p.first])
            {
                if (s != un)
                {
                    adj[s].push_back(un);
                    rev[un].push_back(s);
                }
            }
        }
    }

    for (auto name : names)
    {
        if (found.find(name) == found.end())
        {
            dfsFor(name, adj);
        }
    }

    found.clear();
    reverse(order.begin(), order.end());
    for (auto name : order)
    {
        if (found.find(name) == found.end())
        {
            comp.clear();
            dfsRev(name, rev);
            comps.push_back(comp);
        }
    }

    size_t maxsize = 0;
    for (auto &co : comps)
    {
        maxsize = max(maxsize, co.size());
    }

    cout << c - maxsize << endl;
}