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
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ll n,calcap;
    cin>>n>>calcap;
    vector<ll> courses;
    for (int i = 0; i < n; i++)
    {
        ll cour;
        cin>>cour;
        courses.push_back(cour);
    }
    vector<ll> cals(n);
    ll index = 0;
    cals[0]= calcap;
    for (int i = 1; i < n; i++)
    {
        cals[i] = (2*cals[i-1])/3;
    }
    
    vector<vector<ll> > dpmemory(n + 2,vector<ll>(n+1,0));
    for(auto &c : courses){
        dpmemory[-2][c]=0;
        dpmemory[-1][c]=0;
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            dpmemory[i][j] = max
        }
        
    }

        for (ll a = 0; a < n; ++a) { // For each course
        for (ll b = 0; b <= n; ++b) { // For each level of calories remaining
            // Eat this meal (if possible)
            if (b > 0){
                DP[a+2][b] = max(DP[a+2][b], DP[a+1][b-1] + min(cr[b-1], cal[a]));
            if (a > 0) {
                for (ll k = 0; k <= n; ++k) { // Try all possible previous states
                    DP[a+2][b] = max(DP[a+2][b], DP[a+1][k]);
                }
            }
            DP[a+2][b] = max(DP[a+2][b], DP[a+1][b+1]);
            
                
            
            // Skip this meal
            
            
            // Skip this and previous meal
            
        }
    }
    
    
    
}

// #include <iostream>
// #include <vector>
// using namespace std;
// typedef long long ll;

// int main() {
//     ll n, m;
//     cin >> n >> m;
//     vector<ll> cal(n);
//     for (ll i = 0; i < n; ++i) {
//         cin >> cal[i];
//     }
    
//     // Precompute calories remaining
//     vector<ll> cr(n+1); // Assuming n levels are sufficient; adjust as needed
//     cr[0] = m;
//     for (ll i = 1; i <= n; ++i) {
//         cr[i] = 2 * cr[i-1] / 3;
//     }
    
//     // Initialize DP matrix
//     vector<vector<ll> > DP(n + 2, vector<ll>(n+1, 0)); // Adjusted size to avoid negative indexing

//     // DP calculation
//     for (ll a = 0; a < n; ++a) { // For each course
//         for (ll b = 0; b <= n; ++b) { // For each level of calories remaining
//             // Eat this meal (if possible)
//             if (b > 0){
//                 DP[a+2][b] = max(DP[a+2][b], DP[a+1][b-1] + min(cr[b-1], cal[a]));
//             }
//             if (a > 0) {
//                 for (ll k = 0; k <= n; ++k) { // Try all possible previous states
//                     DP[a+2][b] = max(DP[a+2][b], DP[a+1][k]);
//                 }
//             }
//             DP[a+2][b] = max(DP[a+2][b], DP[a+1][b+1]);
            
                
            
//             // Skip this meal
            
            
//             // Skip this and previous meal
            
//         }
//     }

//     // Find the maximum calories that can be eaten
//     ll result = 0;
//     for (ll i = 0; i <= n; ++i) {
//         result = max(result, DP[n+1][i]);
//     }
//     cout << result << endl;

//     return 0;
// }
