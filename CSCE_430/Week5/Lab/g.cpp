//need top find gcd betwene anynumberand it's self and then find a vlaue that is the best pefect pair power pf p
// exmaple 17 = 17^1 = 1
//25 = 5^2 = 2

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
int main(){
    long long val;
    while(cin>>val){
        if(val==0){
            break;
        }
        long long ans = 1;
        long long index = floor(log2(val));

        for (int i = index; i >= 1; i--) {
            long long powerVal = round(pow(val, 1.0 / i));
            if (pow(powerVal, i) == val) {
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}