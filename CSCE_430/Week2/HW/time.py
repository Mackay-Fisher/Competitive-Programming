firstTime = input()
firstTime = firstTime.split(":")
secondTime = input()
secondTime = secondTime.split(":")
fTH = int(firstTime[0])
fTM = int(firstTime[1])
fTS = int(firstTime[2])
sTH = int(secondTime[0])
sTM = int(secondTime[1])
sTS = int(secondTime[2])
diffHours = (sTH-fTH)
diffMins = (sTM-fTM)
diffSec = (sTS - fTS)
if(diffSec<0):
    diffMins-=1
    diffSec+=60
if(diffMins<0):
    diffHours-=1
    diffMins+=60
if(diffHours<0):
    diffHours+=24
if(diffHours>24):
    diffHours-=24
outputStr = ""
hours= "{:02d}".format(diffHours)
outputStr+= hours + ":"
minutes = "{:02d}".format(diffMins)
outputStr+= minutes + ":"
seconds = "{:02d}".format(diffSec)
outputStr+= seconds
if outputStr == "00:00:00":
    outputStr = "24:00:00"
print(outputStr)
