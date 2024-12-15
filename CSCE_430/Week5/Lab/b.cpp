#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>       
#include <iostream>     
#include <sstream> 
using namespace std;

int main(){
    //1000000 dictionary entries
    unordered_map<string,string> dict;
    string s;
    
    vector<string> message;
    while (getline(cin,s))
    {
        if (s.empty())
        {
            break;
        }
        stringstream a(s);
        string word;
        vector<string> words;
        while (a>>word)
        {
            words.push_back(word);
        }
        if(word=="-1"){
            break;
        }
        if (words.size()==2)
        {
            dict[words[1]]=words[0];
        }
    }
    string test;
    while (cin>>test)
    {
        if (test=="-1")
        {
            break;
        }
        if (test.empty())
        {
            break;
        }
        message.push_back(test);
    }
    for (int i = 0; i < message.size(); i++)
    {
        if (dict.find(message[i])==dict.end())
        {
            cout<<"eh"<<endl;
        }else{
            cout<<dict[message[i]]<<endl;
        }
    }    
}