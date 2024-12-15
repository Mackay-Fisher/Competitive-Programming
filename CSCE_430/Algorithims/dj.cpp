#include<DisjointSet.h>
#include<AlgorithimHelp.h>
using namespace std;
int main(){
    CustomDJ UNF = CustomDJ();
    UNF.p.resize(10);
    UNF.maxH.resize(10,1);
    for(int i=0; i<10;i++){
        UNF.p[i]=i;
    }
    string s; int a; int b;
    while(true){
        cin>>s;
        if(s=="F"){
            cin >> a;
            cout<<UNF.findsetRescursive(a)<<endl;
        }else if (s=="U"){
            cin >> a>>b;
            UNF.merge(a,b);
        }
    }
}