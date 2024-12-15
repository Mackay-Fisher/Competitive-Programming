// L meter lone gerry that cross teh river
// goes back and forth filling up on either side

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> results;
    for (int j = 0; j < n; j++)
    {
        int length;
        int lines;
        cin >> length >> lines;
        queue<int> left;
        queue<int> right;
        length *= 100;
        for (int i = 0; i < lines; i++)
        {
            string side;
            int value;
            cin >> value >> side;
            if (side == "left")
            {
                left.push(value);
            }
            if (side == "right")
            {
                right.push(value);
            }
        }
        bool l = true;
        int trips = 0;
        while (!right.empty()||!left.empty())
        {
            trips++;
            int capacity = length;
            if(l){
                while (!left.empty())
                {
                    if (left.front()<capacity)
                    {
                        capacity-=left.front();
                        left.pop();
                    }else{
                        break;
                    }
                }
                l = false;
            }else{
                while (!right.empty())
                {
                    if (right.front()<capacity)
                    {
                        capacity-=right.front();
                        right.pop();
                    }else{
                        break;
                    }
                }
                l = true;
            }
        }
        results.push_back(trips);
    }
    for (int i = 0; i < results.size(); i++)
    {
        cout<<results[i]<<endl;
    }
}

// 1
// 20 4
// 380 left
// 720 left
// 1340 right
// 1040 left

// 1
// 15 4
// 380 left
// 720 left
// 1340 right
// 1040 left

// 1
// 15 4
// 380 left
// 720 left
// 1340 left
// 1040 left


// 1
// 15 4
// 380 right
// 720 right
// 1340 right
// 1040 right