#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// void printArray(vector<int> killme){
//     for(int value: killme){
//         cout<<value<<" ";
//     }
//     cout<<endl;
// }

int main(){
    int number;
    cin >> number;
    cin.ignore();
    string line;
    getline(cin,line);
    istringstream numParse(line);
    int val;
    vector<int> NumArray;
    while (numParse >> val)
    {
        NumArray.push_back(val);
    }
    vector<int> leftSideMax(number);
    leftSideMax[0] = NumArray[0];
    for(int i =1; i<number; i++){
        leftSideMax[i]=(max(NumArray[i],leftSideMax[i-1]));
    }
    vector<int> rightSideMin(number);
    rightSideMin[number-1] = NumArray[number-1];
    for(int i =number-2; i>=0; i--){
        rightSideMin[i] = min(NumArray[i],rightSideMin[i+1]);
    }
    int validCount = 0;
    for (int i = 0; i < number; i++)
    {
        if (NumArray[i]<=rightSideMin[i] && NumArray[i]>=leftSideMax[i])
        {
            validCount++;
        }
        
    }
    cout<<validCount<<endl;
    return 0;
}

