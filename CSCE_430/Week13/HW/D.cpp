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
ll found;
ll maxscore;
ll maxsize;
string biggest;
const vector<pair<ll, ll>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

class TNode
{
public:
    TNode *chars[26];
    bool endW;
    TNode()
    {
        endW = false;
        for (int i = 0; i < 26; i++)
        {
            chars[i] = nullptr;
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
            int v = ch - 'A';
            if (parent->chars[v] == nullptr)
            {
                parent->chars[v] = new TNode();
            }
            parent = parent->chars[v];
        }
        parent->endW = true;
    }

    ll prefixfound(string pre)
    {
        TNode *cur = base;
        for (char &ch : pre)
        {
            int v = ch - 'A';
            if (cur->chars[v] == nullptr)
            {
                return 0;
            }
            else
            {
                cur = cur->chars[v];
            }
        }
        if (cur->endW)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
};
ll calcScore(string s)
{
    ll size = s.size();
    if (size >= 3 && size < 5)
    {
        return 1;
    }
    if (size == 5)
    {
        return 2;
    }
    if (size == 6)
    {
        return 3;
    }
    if (size == 7)
    {
        return 5;
    }
    if (size >= 8)
    {
        return 11;
    }
    return 0;
}

void dfsPre(string pre, int i, int j, vector<string> &board, vector<vector<bool>> &vis, Trie &triePre, set<string> &found)
{
    
    if (vis[i][j])
    {
        return;
    }

    pre.push_back(board[i][j]);
    ll ret = triePre.prefixfound(pre);

    if (ret == 0)
    {
        return;
    }
    else
    {
        if (ret == 2)
        {
            if (!found.count(pre))
            {
                found.insert(pre);
            }
        }
    }
    for (auto &dri : directions)
    {
        ll x = i + dri.first;
        ll y = j + dri.second;
        if (x >= 0 && x < 4 && y >= 0 && y < 4)
        {
            vis[i][j] = true;
            dfsPre(pre, x, y, board, vis, triePre, found);
            
        }
    }
}

void runP(vector<string> dict, Trie &triePre)
{
    vector<string> board(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> board[i];
    }
    maxscore = 0;
    maxsize = -1;
    string biggest = "";
    set<string> found;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            vector<vector<bool>> visited(4,vector<bool>(4,false));
            string pre = "";
            dfsPre(pre, i, j, board, visited, triePre, found);
        }
    }
    for (auto s : found)
    {
        maxscore += calcScore(s);
        if ((ll)s.size() > maxsize)
        {
            biggest = s;
            maxsize = s.size();
        }
    }
    cout << maxscore << " " << biggest << " " << found.size() << endl;
}

int main()
{
    ll t;
    cin >> t;
    vector<string> words;
    Trie wordTree = Trie();
    wordTree.base = new TNode();
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        words.push_back(s);
        wordTree.addWord(s);
    }
    ll tc;
    cin >> tc;
    while (tc--)
    {
        runP(words, wordTree);
    }
}