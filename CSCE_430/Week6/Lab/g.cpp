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
using namespace std;

class CustomDJ
{
private:
public:
    unordered_map<long long, long long> p;
    set<long long> uniqueParents;

    // This will recursivley find the value of teh base of the set
    long long findsetRescursive(long long x)
    {
        if (p[x] == x)
            return x;
        // Path compression to set the parent of teh current set to the base
        p[x] = findsetRescursive(p[x]);
        return p[x];
    }

    // This will merge base on the value of the max height and then adjust the pointer of the parent to the higher value or just adjust
    void merge(long long a, long long b)
    {
        long long x, y;
        // We find teh sets associated with the values passed in to merge
        x = findsetRescursive(a);
        y = findsetRescursive(b);
        if (x == y)
        {
            return;
        }
        p[x] = y;
        uniqueParents.erase(x);
    }

    void makeSet(long long a)
    {
        if (p.find(a) == p.end())
        {
            uniqueParents.insert(a);
            p[a] = a;
        }
    }
};

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<string> board;
    CustomDJ UNF = CustomDJ();
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        board.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '#')
            {
                UNF.makeSet(i * m + j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '#')
            {
                long long val = i * m + j;

                if (i > 0)
                {
                    if (board[i - 1][j] == '#')
                    {
                        long long cur = (i - 1) * m + j;
                        UNF.merge(val, cur);
                    }

                    if (j > 0)
                    {
                        if (board[i - 1][j - 1] == '#')
                        {
                            long long cur = (i - 1) * m + j - 1;
                            UNF.merge(val, cur);
                        }
                    }

                    if (j < m - 1)
                    {
                        if (board[i - 1][j + 1] == '#')
                        {
                            long long cur = (i - 1) * m + j + 1;
                            UNF.merge(val, cur);
                        }
                    }
                }

                if (i < n - 1)
                {
                    if (board[i + 1][j] == '#')
                    {
                        long long cur = (i + 1) * m + j;
                        UNF.merge(val, cur);
                    }

                    if (j > 0)
                    {
                        if (board[i + 1][j - 1] == '#')
                        {
                            long long cur = (i + 1) * m + j - 1;
                            UNF.merge(val, cur);
                        }
                    }

                    if (j < m - 1)
                    {
                        if (board[i + 1][j + 1] == '#')
                        {
                            long long cur = (i + 1) * m + j + 1;
                            UNF.merge(val, cur);
                        }
                    }
                }

                if (j > 0)
                {
                    if (board[i][j - 1] == '#')
                    {
                        long long cur = i * m + j - 1;
                        UNF.merge(val, cur);
                    }
                }

                if (j < m - 1)
                {
                    if (board[i][j + 1] == '#')
                    {
                        long long cur = i * m + j + 1;
                        UNF.merge(val, cur);
                    }
                }
            }
        }
    }

    cout << UNF.uniqueParents.size() << endl;
}