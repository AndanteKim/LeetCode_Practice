class TrieNode:
    def __init__(self):
        self.word_count = 0
        self.count = 0
        self.children = dict()

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr.children[c].count += 1
            curr = curr.children[c]
        curr.word_count += 1

    def countWordsEqualTo(self, word: str) -> int:
        curr = self.root
        for c in word:
            if c not in curr.children:
                return 0
            curr = curr.children[c]
        return curr.word_count

    def countWordsStartingWith(self, prefix: str) -> int:
        curr = self.root
        for c in prefix:
            if c not in curr.children:
                return 0
            curr = curr.children[c]
        return curr.count

    def erase(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                return
            curr = curr.children[c]
        
        curr = self.root
        for c in word:
            curr.children[c].count -= 1
            curr = curr.children[c]
        
        if curr.word_count == 0:
            return
        curr.word_count -= 1
            


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.countWordsEqualTo(word)
# param_3 = obj.countWordsStartingWith(prefix)
# obj.erase(word)