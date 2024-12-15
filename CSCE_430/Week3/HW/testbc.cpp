#include<vector>
#include<string>
#include<set>
#include <iostream>
#include <map>
#include<stack>
using namespace std;


int main(){
    int num;
    cin>>num;
    cin.ignore();
    vector<int> output;
    vector<vector<int> > validStacks(num+1);
    for(int i=1; i<=num; i++){
        char type;
        int num1 = 0,num2 =0;
        cin>>type;
        if (type == 'a'){
            cin>>num1;
            validStacks[i] = validStacks[num1];
            validStacks[i].push_back(i);
        }else if (type == 'b'){
            cin>>num1;
            validStacks[i] = validStacks[num1];
            cout<<validStacks[i][validStacks[i].size()-1]<<"\n";
            validStacks[i].pop_back();
        }else if(type == 'c'){
            cin>>num1>>num2;
            validStacks[i] = validStacks[num1];
            map<int,int> checkHash;
            int diffCount = 0;
            for(int j=0; j<validStacks[i].size();j++){
                checkHash[validStacks[i][j]]++;
            }
            for(int j=0; j<validStacks[num2].size(); j++){
                checkHash[validStacks[num2][i]]--;
            }
            for( auto& pair: checkHash){
                if(pair.second!=0){
                    diffCount++;
                }
            }
            cout<<diffCount<<"\n";
        }
        // for(int x=0; x<=num; x++){
        //     cout<<"Vector "<<x<<":"<<"( ";
        //     for(int j=0; j<validStacks[x].size(); j++){
        //         cout<<validStacks[x][j]<<" ";
        //     }
        //     cout<<")"<<endl;
        // }
        // cout<<endl;
    }
    // for(auto&v : output){
    //     cout<<v<<"\n";
    // }
}