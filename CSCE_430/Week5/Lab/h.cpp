// Triple ended queue
// insert fron
// insert back
// insert middle
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
/*
The teque supports the following four operations:

push_back x: insert the element
 into the back of the teque.

push_front x: insert the element
 into the front of the teque.

push_middle x: insert the element
 into the middle of the teque. The inserted element
 now becomes the new middle element of the teque. If
 is the size of the teque before the insertion, the insertion index for
 is
 (using
-based indexing).

get i: prints out the
 index element (
-based) of the teque.
*/
int main()
{
    int n;
    cin>>n;
    vector<int> teque;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if (s=="push_back")
        {
            int x;
            cin>>x;
            teque.push_back(x);

        }
        if (s=="push_front")
        {
            int x;
            cin>>x;
            teque.insert(teque.begin(),x);
        }
        if (s=="push_middle")
        {
            int x;
            cin>>x;
            int middle = 0;
            if (teque.size()%2==0)
            {
                middle = teque.size()/2;
            }else{
                middle = teque.size()/2 + 1;
            }
            teque.insert(teque.begin()+middle,x);
        }
        if (s=="get")
        {
            int x;
            cin>>x;
            // cout<<teque[x]<<endl;
        }
    }
    for (int i = 0; i < teque.size(); i++)
    {
        cout<<teque[i]<<endl;
    }
}