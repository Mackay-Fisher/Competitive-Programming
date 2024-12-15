//Gallery has 2n rooms, the gallery is laid out as N rows of 2 rooms side by side
//Visitors must close off k of the rooms in each row
//Doors connect all adjacent rooms (north-south and east-west, but not diagonally). 
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
#include<set>
using namespace std;
typedef long long ll;
vector< vector <vector <ll> > > boardStates;
vector< vector< ll > > board;
ll recursiveState(ll rowLeft, ll rowLevel, ll decision){
    // cout<<rowLeft<<"  "<<rowLevel<<"  "<<decision<<"    "<<endl;
    if(rowLeft <= 0){
        return 0;
    }
    // cout<<"Passed Check"<<endl;
    if(rowLevel<0){
        return INT16_MAX;
    }
    // cout<<"Passed Check"<<endl;
    if (decision==2)
    {
        boardStates[rowLeft][rowLevel][decision] = min(recursiveState(rowLeft,rowLevel,0),recursiveState(rowLeft,rowLevel,1));
        return boardStates[rowLeft][rowLevel][decision];
    }
    // cout<<"Passed Check"<<endl;
    if(boardStates[rowLeft][rowLevel][decision]!=-1){
        return boardStates[rowLeft][rowLevel][decision];
    }
    // cout<<"Passed Check"<<endl;
    ll boardVal = board[rowLevel][decision];
    ll closeBack = recursiveState(rowLeft-1,rowLevel-1,decision) + boardVal;
    ll bestPState = recursiveState(rowLeft,rowLevel-1,2);
    ll res = min(closeBack,bestPState);
    boardStates[rowLeft][rowLevel][decision] =  res;
    return res;
}

int main(){
    ll n,k;
    cin>>n>>k;
    //I need to get precomputed values for the number of doors that need to be closed
    //because doors connect to next to and above but not diagonal and I cannot close diagonal
    //Top down apprach we need to find teh most optimal choice at each row 
    //Three cases:
    //The row you are on
    //The amount of rooms left
    //The palced cone that is possible choice R L N
    vector<vector<ll> > Tboard(n);
    ll Gallerysum=0;
    for (int i = 0; i <n; i++)
    {
        ll l,r;
        cin>>l>>r;
        Tboard[i].push_back(l);
        Tboard[i].push_back(r);
        Gallerysum += l;
        Gallerysum += r;
    }
    ll b1,b2;
    cin>>b1>>b2;
    vector<vector<vector<ll> > > TboardStates(k+1);
    for (int i = 0; i <=k; i++)
    {
        vector<vector<ll> > boardVal(n);
        for (int j = 0; j < n; j++)
        {
            vector<ll> decisions(3, -1);
            boardVal[j] = decisions;
        }
        
        TboardStates[i] = boardVal;
    }
    boardStates = TboardStates;
    board = Tboard;

    // for (auto &a: board)
    // {
    //     for (size_t i = 0; i < a.size(); i++)
    //     {
    //         cout<<a[i]<<"   ";
    //     }
    //     cout<<endl;
        
    // }
    ll minCost =  min(recursiveState(k,n-1,0),recursiveState(k,n-1,1));
    // cout<<minCost<<endl;
    cout<<Gallerysum - minCost<<endl;
    return 0;
}