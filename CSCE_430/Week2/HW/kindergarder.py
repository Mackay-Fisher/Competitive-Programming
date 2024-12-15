numStudents = input()
newArray = []
rangeVal = len(numStudents)
for i in range(len(numStudents)):
    newArray.append(numStudents[i])
numZ = 0
numOn = 0
numTwo = 0
for i in range(len(newArray)):
    if int(newArray[i]) == 0:
        numZ += 1
    if int(newArray[i]) == 1:
        numOn += 1
    if int(newArray[i]) == 2:
        numTwo += 1

swaps = 0
zeros = 0
# ones = numZ
# twos = numOn + numZ
for i in range(len(newArray)):
    if int(newArray[i]) == 0:
        # for j in reversed(range(i+1)):
        #     # if j==zeros:
        #     #     break
        #     # temp = newArray[j-1]
        #     # newArray[j-1] = newArray[j]
        #     # newArray[j] = temp
        #     newArray[j] = newArray[j-1]
        # newArray[zeros] = 0
        swaps += i - zeros
        zeros += 1
    # print(newArray)
otArray = []
for i in range(len(newArray)):
    if int(newArray[i])!= 0:
        otArray.append(newArray[i])
        
# print(otArray)

ones = 0
for i in range(len(otArray)):
    if int(otArray[i]) == 1:
        swaps += i-ones
        ones += 1
print(swaps)


# for i in range(zeros, len(newArray)):
#     if int(newArray[i]) == 1:
#         swaps += i-ones
#         ones += 1
# print(swaps)