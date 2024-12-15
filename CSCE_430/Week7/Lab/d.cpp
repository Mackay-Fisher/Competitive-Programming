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
using namespace std;

// disjoint set (union find)
#include <vector>
#include <stack>

class disjoint_set {
    private:
        std::vector<int> parent;
        std::vector<int> max_height;
        std::vector<int> _size;
    public:
        disjoint_set(int n) {
            parent = std::vector<int>(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            max_height = std::vector<int>(n, 1);
            _size = std::vector<int>(n, 1);
        }
        void merge(int a, int b) {
            // find root
            int x, y;
            x = find(a);
            y = find(b);
            // if within same set, return
            if (x == y) {
                return;
            }
            // union by rank (union smaller into larger set)
            if  (max_height[x] > max_height[y]) {
                parent[y] = x;
                _size[x] += _size[y];
            } else if (max_height[y] > max_height[x]) {
                parent[x] = y;
                _size[y] += _size[x];
             } else {
                parent[y] = x;
                ++max_height[x];
                _size[x] += _size[y];
             }
        }

        int find(int x) {
            // if x is root, return
            if (parent[x] == x) return x;
            // node along path for path compression
            std::stack<int> pointer_to_update;
            while (parent[x] != x) {
                pointer_to_update.push(x);
                x = parent[x];
            }
            // update node parent
            int root = x;
            while (!pointer_to_update.empty()) {
                parent[pointer_to_update.top()] = root;
                pointer_to_update.pop();
            }
            return root;
        }

        int size(int a) {
            int x = find(a);
            return _size[x];
        }

        // recursive find
        // int find(int x) {
        //     // if x is root, return
        //     if (p[x] == x) {
        //         return x;
        //     }
        //     // path compression
        //     p[x] = find(p[x]);
        //     // return root
        //     return p[x];
        // }
};

int main() {
    // Your code here
    int n;
    cin >> n;
    unordered_map<int,vector<int> > m;
    vector<pair<pair<int,int>,int> > res(n-1);
    int idx = 0;
    disjoint_set s(n + 1);
    for (int i = 0; i < n; i++) {
        int _size;
        cin >> _size;
        for (int j = 0; j < _size; j++) {
            int num;
            cin >> num;
            if (m.find(num) != m.end()) {
                for (int val : m[num]) {
                    if (s.find(val) != s.find(i + 1)) {
                        s.merge(val, i + 1);
                        res[idx++] = {{val, i + 1}, num};
                        break;
                    }
                }
            }
            m[num].push_back(i + 1);
        }
    }
    // for (pair<int,vector<int> > p : m) {
    //     cout << p.first;
    //     print(p.second);
    // }
    if (s.size(1) != n) {
        printf("impossible\n");
    } else {
        for (int i = 0; i < res.size(); i++) {
            printf("%d %d %d\n", res[i].first.first, res[i].first.second, res[i].second);
        }
    }
    return 0;
}