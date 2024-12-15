#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

class CustomDJ
{
private:
public:
    unordered_map<long long, long long> p;
    unordered_map<int, int> maxVal;
    unordered_map<long long, long long> value;
    set<long long> uniqueParents;
    long long maxValue = 0;
    // This will recursivley find the value of teh base of the set
    long long findsetRescursive(long long x)
    {
        if (p[x] == x)
            return x;
        // Path compression to set the parent of teh current set to the base
        p[x] = findsetRescursive(p[x]);
        return p[x];
    }

    // This will then store them to be updated in a stack does not rely on recursion depth but also is not as fast
    //  int findsetStack(in x){
    //      if(p[x]==x) return x;
    //      stack<int> pointerUpdate;
    //      while (p[x]!=x)
    //      {
    //          pointerUpdate.push(x);
    //          x = p[x];
    //      }
    //      int setNumber = x;
    //      while (!pointerUpdate.empty())
    //      {
    //          p[pointerUpdate.top()]= setNumber;
    //          pointerUpdate.pop();
    //      }

    //     return setNumber;
    // }
    // This will merge base on the value of the max height and then adjust the pointer of the parent to the higher value or just adjust
    void merge(long long a, long long b)
    {
        long long x, y;
        // We find teh sets associated with the values passed in to merge
        x = findsetRescursive(a);
        y = findsetRescursive(b);
        if(x==y){
            return;
        }
        p[x] = y;
        value[y] += value[x];
        value[x] = 0;
        uniqueParents.erase(x);
    }

    void makeSet(long long x, long long c)
    {
        if (p.find(x) == p.end())
        {
            uniqueParents.insert(x);
            p[x] = x;
            value[x] = c;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    CustomDJ UNF = CustomDJ();
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        UNF.makeSet(i, val);
    }
    for (int i = 0; i < m; i++)
    {
        long long a, b;
        cin>>a>>b;
        UNF.merge(a, b);
    }
    for (auto &a : UNF.uniqueParents)
    {
        if (UNF.value[a] != 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
    return 0;
}