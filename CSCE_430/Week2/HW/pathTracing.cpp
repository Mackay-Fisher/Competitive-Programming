
// void printArray(vector<string> killme){
//     for(string value: killme){
//         cout<<value<<" ";
//     }
//     cout<<endl;
// }


//input:
// down
// down
// left
// left
// up
// up
// up
// left
// left
// -1


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void printMap(map< int,pair<int,int> > orderPairMap){
    for (const auto &elem : orderPairMap) {
        std::cout << elem.first << " -> (" << elem.second.first << ", " << elem.second.second << ")" << std::endl;
    }
}
void printOutput(vector<vector<char> > map,int width, int height){
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}
int main(){
    map< int,pair<int,int> > orderPairMap;
    int cR =0, cL = 0, cU =0, cD =0, index = 0;
    string line;
    orderPairMap[index] = make_pair(0,0); 
    while (cin>>line){   
        if (line=="-1")
        {
            break;
        }
        index++;
        if (line=="down")
        {
            cD++;
            pair<int,int> curPos = orderPairMap[index-1];
            pair<int,int> newPos = make_pair(curPos.first,curPos.second+1);
            orderPairMap[index] = newPos;
        }else if(line=="up"){
            cU++;
            pair<int,int> curPos = orderPairMap[index-1];
            pair<int,int> newPos = make_pair(curPos.first,curPos.second-1);
            orderPairMap[index] = newPos;
        }else if(line=="left"){
            cL++;
            pair<int,int> curPos = orderPairMap[index-1];
            pair<int,int> newPos = make_pair(curPos.first-1,curPos.second);
            orderPairMap[index] = newPos;
        }else if (line=="right")
        {
            cR++;
            pair<int,int> curPos = orderPairMap[index-1];
            pair<int,int> newPos = make_pair(curPos.first+1,curPos.second);
            orderPairMap[index] = newPos;
        }
    }
    int miX =0, miY=0,maX=0,maY=0;
    for(int i=0; i<=index;i++){
        pair<int,int> curPos = orderPairMap[i];
        maX = max(maX,curPos.first);
        miX = min(miX,curPos.first);
        maY = max(maY,curPos.second);
        miY = min(miY,curPos.second);
    }
    // cout<<maX<<" "<<miX<<" "<<maY<<" "<<miY<<endl;
    int width = (maX-miX) + 3;
    int height = (maY-miY) + 3;
    // cout<<width<<"    "<<height<<endl;
    int minOffsetX = -miX;
    int minOffsetY = -miY;
    vector<vector<char> > map(height,vector<char>(width));

    // char ** map = new char*[width];
    // for(int i=0; i<width; i++){
    //     map[i] = new char[height];
    // }
    for(int i =0; i <height; i++){
        for(int j=0; j<width; j++){
            if(i==0||i==height-1||j==0||j==width-1){
                map[i][j] = '#';
            }else{
                map[i][j] = ' ';
            }
        }
    }
    // printMap(orderPairMap);
    for(int i=0; i<=index;i++){
        pair<int,int> curPos = orderPairMap[i];
        pair<int,int> newPos = make_pair(curPos.first + minOffsetX, curPos.second + minOffsetY);
        orderPairMap[i] = newPos;
    }
    // printMap(orderPairMap);
    pair<int,int> startPair;
    for(int i=0; i<=index;i++){
        pair<int,int> curPos = orderPairMap[i];
        if(i==0){
            startPair = make_pair(curPos.second+1,curPos.first+1);
            map[curPos.second+1][curPos.first+1] = 'S';
        } else if(i == index){
            map[curPos.second+1][curPos.first+1] = 'E';
        }else{
            auto temp = startPair;
            if (!(curPos.second+1==temp.first && curPos.first+1==temp.second))
            {
                map[curPos.second+1][curPos.first+1] = '*';
            }
        }
    }
    printOutput(map,width,height);
    return 0;
}