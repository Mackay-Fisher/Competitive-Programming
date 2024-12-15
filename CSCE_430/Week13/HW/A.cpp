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
class TNode
{
public:
    TNode *chars[26];
    ll count;
    TNode()
    {
        count = 0;
        for (auto a : chars)
        {
            a = nullptr;
        }
    }
};
class Trie
{

public:
    TNode *base;

    void addWord(string s)
    {
        TNode *parent = base;
        for (char &ch : s)
        {
            int v = ch - 'a';
            if (parent->chars[v] == nullptr)
            {
                parent->chars[v] = new TNode();
            }
            parent = parent->chars[v];
            parent->count++;
        }
    }

    ll prefixfound(string pre)
    {
        TNode *cur = base;
        for (char &ch : pre)
        {
            int v = ch - 'a';
            if (cur->chars[v] == nullptr)
            {
                return 0;
            }
            else
            {
                cur = cur->chars[v];
            }
        }
        return cur->count;
    }
};

int main()
{
    ll numStrings;
    cin >> numStrings;
    vector<string> words;
    Trie wordTree = Trie();
    wordTree.base = new TNode();
    for (int i = 0; i < numStrings; i++)
    {
        string s;
        cin >> s;
        cout << wordTree.prefixfound(s) << endl;
        wordTree.addWord(s);
    }
}