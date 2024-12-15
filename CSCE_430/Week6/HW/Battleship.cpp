#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int size, ships;
    cin >> size >> ships;
    vector<string> board;
    for (int i = 0; i < size; i++)
    {
        string s;
        cin >> s;
        board.push_back(s);
    }
    vector<long long> Ships;
    for (int i = 0; i < ships; i++)
    {
        long long ship;
        cin >> ship;
        Ships.push_back(ship);
    }
    vector<pair<int, int> > ValidSHipPairs;
    unordered_map<int, vector<set<pair<long long, long long> > > > PlacmentsMap;
    set<pair<long long, long long> > hitLoactions;
    for (int i = 0; i < Ships.size(); i++)
    {
        long long sizeShip = Ships[i];
        int validShips = 0;
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {

                if (k + sizeShip - 1 < size)
                {
                    int val_O = 0;
                    int val_X = 0;
                    set<pair<long long, long long> > temp;
                    for (int z = k; z < sizeShip + k; z++)
                    {
                        if (board[j][z] == 'X')
                        {
                            val_X++;
                        }
                        else if (board[j][z] == 'O')
                        {
                            hitLoactions.insert(make_pair(j, z));
                            val_O++;
                        }
                        temp.insert(make_pair(j, z));
                    }
                    if (val_O < sizeShip && val_X == 0)
                    {
                        PlacmentsMap[i].push_back(temp);
                        validShips++;
                    }
                }
                if (sizeShip > 1)
                {
                    if (j + sizeShip - 1 < size)
                    {
                        int val_O = 0;
                        int val_X = 0;
                        set<pair<long long, long long> > temp;
                        for (int w = j; w < sizeShip + j; w++)
                        {
                            if (board[w][k] == 'X')
                            {
                                val_X++;
                            }
                            else if (board[w][k] == 'O')
                            {
                                hitLoactions.insert(make_pair(w, k));
                                val_O++;
                            }
                            temp.insert(make_pair(w, k));
                        }
                        if (val_O < sizeShip && val_X == 0)
                        {
                            PlacmentsMap[i].push_back(temp);
                            validShips++;
                        }
                    }
                }
            }
        }
    }
    if (ships == 1)
    {
        cout << ValidSHipPairs[0].second << endl;
    }
    if (ships == 2)
    {
        long long total = 0;
        for (auto &a : PlacmentsMap[0])
        {
            for (auto &b : PlacmentsMap[1])
            {
                bool valid = true;
                set<pair<long long, long long> > palcedShip2 = b;

                for (auto &c : a)
                {
                    if (palcedShip2.find(c) != palcedShip2.end())
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    total++;
                }
            }
        }
        cout << total << endl;
    }
    if (ships == 3)
    {
        long long total = 0;
        for (auto &a : PlacmentsMap[0])
        {
            set<pair<long long, long long> > HitSpots;
            for (auto &s : a)
            {
                if (hitLoactions.find(s) != hitLoactions.end())
                {
                    HitSpots.insert(s);
                }
            }

            for (auto &b : PlacmentsMap[1])
            {
                bool validB = true;
                for (auto &s : b)
                {
                    if (a.find(s) != a.end())
                    {
                        validB = false;
                        break;
                    }
                    if (hitLoactions.find(s) != hitLoactions.end())
                    {
                        HitSpots.insert(s);
                    }
                }
                if (!validB)
                {
                    continue;
                }
                for (auto &c : PlacmentsMap[2])
                {
                    bool validC = true;
                    for (auto &s : c)
                    {
                        if (a.find(s) != a.end() || b.find(s) != b.end())
                        {
                            validC = false;
                            break;
                        }
                        if (hitLoactions.find(s) != hitLoactions.end())
                        {
                            HitSpots.insert(s);
                        }
                    }
                    if (validC)
                    {
                        if (HitSpots==hitLoactions)
                        {
                            total++;
                        }
                        
                    }
                }
            }
        }
        cout <<total << endl;
    }
}