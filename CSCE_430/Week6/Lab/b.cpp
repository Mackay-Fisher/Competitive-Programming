#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <map>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool ValThenString(pair<string, long long>& a, pair<string, long long>& b) {
    if (a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main()
{
    long long testcases;
    cin >> testcases;

    for (long long i = 0; i < testcases; i++)
    {
        long long n;
        cin >> n;
        map<long long, string> nameMap;
        vector<pair<string, long long> > ClassTotals;
        for (long long j = 0; j < n; j++)
        {
            string name;
            string classhe;
            cin >> name >> classhe;
            string burn;
            cin >> burn;
            vector<string> classForName;
            // I looked up how to parse a string by a toke in cpp
            string classS;
            istringstream ClassStream(classhe);
            while (getline(ClassStream, classS, '-'))
            {
                classForName.push_back(classS);
            }
            string cutname;
            for (int i = 0; i < name.size() - 1; i++)
            {
                cutname += name[i];
            }
            long long Total = 0;
            int index = 0;
            //Pad with middle before checking;
            long long remainder = 10-classForName.size();
            string compare = "";
            while (remainder)
            {
                compare+="2";
                Total += 2 * pow(10,index);
                remainder--;
                index++;
            }
            
            for (auto &s : classForName)
            {
                if (s == "upper")
                {
                    compare+="3";
                    Total += 3*pow(10,index);
                }
                if (s == "middle")
                {
                    compare+="2";
                    Total += 2*pow(10,index);
                }
                if (s == "lower")
                {
                    compare+="1";
                    Total += 1*pow(10,index);
                }
                index++;
            }
            pair<string,long long> pairVal = make_pair(cutname,Total);
            ClassTotals.push_back(pairVal);
        }
        sort(ClassTotals.begin(), ClassTotals.end(), ValThenString);

        for (auto &a : ClassTotals)
        {
            cout <<a.first<< endl;
        }
        cout << "==============================" << endl;
    }
}