#include <iostream>
using namespace std;
int main(){
    long long inp;
    cin>>inp;
    while(inp){
        cout<<inp<<" ";
        if(inp==1){
            break;
        }
        else if(inp%2==0){
            inp /= 2;
        }else{
            inp *= 3;
            inp++;
        }
        
    }
}