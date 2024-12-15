//This is a game of chess
//In the eight queens puzzle, eight queens must be placed on a standard chess board so that no queen can attack another.
//Given a chess board with queens at * and . as empty spaces
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    vector<string> board;
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin>>s;
        board.push_back(s);
    }
    int queens = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j]=='*')
            {
                queens++;
                //up and acroos
                for (int k = 0; k < 8; k++)
                {
                    if (board[i][k]=='*'&&k!=j)
                    {
                        cout<<"invalid"<<endl;
                        return 0;
                    }
                    if (board[k][j]=='*'&&k!=i)
                    {
                        cout<<"invalid"<<endl;
                        return 0;
                    }
                }
                int x = i;
                int y = j;
                while (x<8&&y<8)
                {
                    if (board[x][y]=='*'&&x!=i&&y!=j)
                    {
                        cout<<"invalid"<<endl;
                        return 0;
                    }
                    x++;
                    y++;
                }
                x = i;
                y = j;
                while (x>=0&&y>=0)
                {
                    if (board[x][y]=='*'&&x!=i&&y!=j)
                    {
                        cout<<"invalid"<<endl;
                        return 0;
                    }
                    x--;
                    y--;
                }
                x = i;
                y = j;
                while (x>=0&&y<8)
                {
                    if (board[x][y]=='*'&&x!=i&&y!=j)
                    {
                        cout<<"invalid"<<endl;
                        return 0;
                    }
                    x--;
                    y++;
                }
                x = i;
                y = j;
                while (x<8&&y>=0)
                {
                    if (board[x][y]=='*'&&x!=i&&y!=j)
                    {
                        cout<<"invalid"<<endl;
                        return 0;
                    }
                    x++;
                    y++;
                }
            }
        }
    }
    if (queens!=8)
    {
        cout<<"invalid"<<endl;
    }else{
        cout<<"valid"<<endl;
    }
}