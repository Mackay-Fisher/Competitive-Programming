#include<vector>
#include<iostream>
#include<string>
using namespace std;

int lps(string &s, int i, int j, vector<vector<int>> &dp){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i>j) return 0;
    if(i==j) return 1;
    if(s[i]==s[j]) dp[i][j] = 2 + lps(s,i+1,j-1,dp);
    if(s[i]!=s[j]) dp[i][j] = max(lps(s,i+1,j,dp), lps(s,i,j-1,dp));
    return dp[i][j];
}