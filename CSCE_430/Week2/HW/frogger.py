frogger = input()
frogger = frogger.split()
numSquares = int(frogger[0])
startIndex = int(frogger[1])-1
targetNum = int(frogger[2])
gameArray = input()
gameArray = gameArray.split()
gameArray = list(map(int, gameArray))
curval =gameArray[startIndex]
if(curval==targetNum):
    print("magic")
    print(0)
    exit()
    
jumps = 0
spotsVisited = set()
while(True):
    jumps+=1
    curval = gameArray[startIndex]
    spotsVisited.add(startIndex)
    if((curval + startIndex) >= numSquares):
        print("right")
        print(jumps)
        break
    if((curval + startIndex) < 0):
        print("left")
        print(jumps)
        break
    if(gameArray[startIndex+curval]==targetNum):
        print("magic")
        print(jumps)
        break
    if(startIndex+curval in spotsVisited):
        print("cycle")
        print(jumps)
        break
    startIndex += curval

    
    
