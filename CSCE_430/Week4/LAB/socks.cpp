#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> aux;
    stack<int> base;
    int number;
    cin>>number;
    for(int i=0; i<number*2; i++){
        int n;
        cin>>n;
        base.push(n);
    }
    int moves = 0;
    while (!base.empty()||!aux.empty()){
        if(aux.top()==base.top()){
            aux.pop();
            base.pop();
            moves++;
        }
        if(aux.top()!=base.top()){
            if (!base.empty())
            {
                aux.push(base.top());
                base.pop();
                moves++;
            }else if (!aux.empty())
            {
                base.push(aux.top());
                aux.pop(); 
                moves++;
            }
        }
    }
    cout<<moves;
}