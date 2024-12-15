// take in input in base 8
// convert to base 10 then base 16
// output in base 16

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
int OctalToBinary(int octalNum)
{
    int decimalNum = 0, binaryNum = 0, count = 0;

    while (octalNum != 0)
    {
        decimalNum += (octalNum % 10) * pow(8, count);
        ++count;
        octalNum /= 10;
    }
    count = 1;
    while (decimalNum != 0)
    {
        binaryNum += (decimalNum % 2) * count;
        decimalNum /= 2;
        count *= 10;
    }
    return binaryNum;
}
int main()
{
    string input;
    cin >> input;
    string binary = "";
    string b1 = "";
    string b2 = "";
    string b3 = "";
    string b4 = "";
    
    for (long long i = 0; i < input.size(); i += 4)
    {
        if (i < input.size() - 1)
        {
            
        }
        if (i + 1 < input.size() - 1)
        {
            /* code */
        }
        if (i + 2 < input.size() - 1)
        {
            /* code */
        }
        if (i + 3 < input.size() - 1)
        {
            /* code */
        }
    }
}