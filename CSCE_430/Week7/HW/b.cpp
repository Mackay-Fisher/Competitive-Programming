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
int main(){
    string line;
    while(getline(cin,line)){
        stringstream inputs(line);
        vector<long long> inputStream;
        long long word;
        while (inputs>>word)
        {
            inputStream.push_back(word);
        }
        long long n = inputStream.at(0);
        long long m = inputStream.at(1);
        vector<long long> checkNums(m);
        for (int i = 0; i < m; i++)
        {
            checkNums[i] = inputStream.at(i+2);
        }
        vector<long long> arrayBuild(n+1);
        vector<bool> WinLoss(n+1);
        WinLoss[0]= false;
        WinLoss[1]= true;
        for (int i = 2; i < n+1; i++)
        {
            bool win = false;
            for (int j = 0; j < checkNums.size(); j++)
            {
                
                if (i-checkNums[j]>=0)
                {
                    if (!WinLoss[i-checkNums[j]])
                    {
                        win = true;
                        break;
                    }
                    
                }
                
            }
            WinLoss[i]=win;
        }
        if(WinLoss[n]){
            cout<<"Stan wins"<<endl;
        }else{
            cout<<"Ollie wins"<<endl;
        }
    }
}