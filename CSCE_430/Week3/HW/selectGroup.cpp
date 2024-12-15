// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <set>
// #include <sstream>
// using namespace std;
// int main(){
//     string nextToken;
//     vector<string> ListTask;
    
//     while (getline(cin,nextToken)) {
//         if(nextToken=="-1"){
//             break;
//         }
//         ListTask.push_back(nextToken);
//     }
//     unordered_map< string, set<string> > groupSets(ListTask.size());
//     for(int i=0; i<ListTask.size(); i++){
        
//         stringstream lineProcess (ListTask[i]);
//         vector<string> currentLine;
//         string token;
//         while(lineProcess>>token){
//             currentLine.push_back(token);
//         }
//         if (currentLine[0] == "group"){
//             set<string> groups;
//             for(int j =3; j< stoi(currentLine[2])+3; j++){
//                 groups.insert(currentLine[j]);
//             }
//             groupSets[currentLine[1]] = groups;
//         }
//         else{
//             vector<set<string>> setStack;
//             for (int i = currentLine.size()-1; i >= 0; i--)
//             {
//                 if (currentLine[i]=="union"||currentLine[i]=="difference"||currentLine[i]=="intersection")
//                 {
//                     auto s1 = setStack[setStack.size()-1];
//                     setStack.pop_back();
//                     auto s2 = setStack[setStack.size()-1];
//                     setStack.pop_back();

//                     if (currentLine[i]=="union"){
//                         setStack.push_back()
//                     }
//                 }
                
//             }
            
//         }
//     }

//     for(auto g: groupSets){
//         for(auto &k: g.second ){
//             cout<<k<<" ";
//         }
//         cout<<endl;
//     }




// }

// import collections
// groups = collections.defaultdict(list)
// inputLines = []
// output = []
// while True:
//     try:
//         vals = input()
//         if vals == "-1":
//             break
//         inputLines.append(vals)
//     except:
//         break
       
// for i in range(len(inputLines)):
//     currentLine = inputLines[i].split()
//     if currentLine[0]=="group":
//         newset = set()
//         for j in range(int(currentLine[2])):
//            newset.add(currentLine[j+3])
//         groups[currentLine[1]].append(newset)
//     else:
//         stack = []
//         for element in reversed(currentLine):
//             if element in ["union", "difference", "intersection"]:
//                 set1 = stack.pop()
//                 set2 = stack.pop()
//                 if element == "union":
//                     stack.append(set1.union(set2))
//                 elif element == "difference":
//                     stack.append(set1.difference(set2))
//                 elif element == "intersection":
//                     stack.append(set1.intersection(set2))
//             else:
//                 stack.append(groups[element][0])
//         if stack:
//             output.append(stack[0])
//         else:
//             output.append['empty']
// print(output)