class TrieNode():
    def __init__(self):
        self.c = {}
        self.w = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for w in word:
            if w not in cur.c:
                cur.c[w] = TrieNode()
            cur = cur.c[w]
        cur.w = True

    def search(self, word: str) -> bool:
        cur = self.root
        for w in word:
            if w not in cur.c:
                return False
            cur = cur.c[w]
        return cur.w


    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for w in prefix:
            if w not in cur.c:
                return False
            cur = cur.c[w]
        return True
