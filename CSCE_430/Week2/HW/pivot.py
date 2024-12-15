number = int(input())
numsArray = input()
numsArray = numsArray.split()
numsArray = list(map(int, numsArray))
validCount = 0
for i in range(number):
    val = numsArray[i]
    for j in range(number+1):
        if j == number:
            validCount+=1
            break
        elif j == i:
            continue
        elif i > j and val < numsArray[j]:
            break
        elif i < j and val > numsArray[j]:
            break
print(validCount)

#include <iostream>
#include <sstream>
#include <vector>
#include <string>