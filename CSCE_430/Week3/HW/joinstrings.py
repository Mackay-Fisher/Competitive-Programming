import sys
numStrings = int(sys.stdin.readline())
strings = []
output = []
for i in range(numStrings-1):
    ind1,ind2  = map(int,sys.stdin.readline().split())
    ind1 -=1
    ind2 -=1
    strings[ind1] = strings[ind1] + strings[ind2]
    strings[ind2] = ""

for i in range(len(strings)):
    if strings[i]!="":
        print(strings[i])
        break
    
      