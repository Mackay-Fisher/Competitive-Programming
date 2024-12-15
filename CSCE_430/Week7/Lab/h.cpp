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
int main()
{
    string d1;
    string d2;
    stack<char> bA;
    stack<char> bB;
    cin>>d1>>d2;
    for (auto &c : d1)
    {
        bA.push(c);
    }
    for (auto &c : d2)
    {
        bB.push(c);
    }
    while (!bB.empty() && !bA.empty())
    {
        char a = bA.top();
        bA.pop();
        char b = bB.top();
        bB.pop();
        if (a != b)
        {
            bA.push(a);
            bB.push(b);
            break;
        }
    }
    stack<char> A;
    stack<char> B;
    while (!bA.empty())
    {
        A.push(bA.top());
        bA.pop();
    }
    while (!bB.empty())
    {
        B.push(bB.top());
        bB.pop();
    }
    while (!B.empty() && !A.empty())
    {
        char a = A.top();
        A.pop();
        char b = B.top();
        B.pop();
        if (a != b)
        {
            A.push(a);
            B.push(b);
            break;
        }
    }
    cout<<B.size()<<endl;

}