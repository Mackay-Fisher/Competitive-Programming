#I modefied a trie structure that I made form leet code and teh repurposed the insert function to check for the numerical values
class TrieNode:
    def __init__(self):
        self.numbers = {}
        self.Enum = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, number):
        checkNode = self.root
        for digit in number:
            if digit not in checkNode.numbers:
                checkNode.numbers[digit] = TrieNode()
            checkNode = checkNode.numbers[digit]
            if checkNode.Enum:
                return False
        checkNode.Enum = True
        return len(checkNode.numbers) == 0


testcases = int(input())
responses = []
for i in range(testcases):
    numofNumbers = int(input())
    phoneTrie = Trie()
    prefixFound = False
    for i in range(numofNumbers):
        phoneNumber = input()
        if not phoneTrie.insert(phoneNumber):
            prefixFound = True
            
    if(prefixFound):
         responses.append("NO")
    else:  
        responses.append("YES")
for res in responses:
    print(res)