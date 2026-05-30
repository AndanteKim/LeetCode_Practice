class TrieNode:
    def __init__(self):
        self.shortest_len = float('inf')
        self.index = -1
        self.children = dict()

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str, idx: int) -> None:
        curr, n = self.root, len(word)
        if n < curr.shortest_len:
            curr.index = idx
            curr.shortest_len = n
        for i in range(n - 1, -1, -1):
            if word[i] not in curr.children:
                curr.children[word[i]] = TrieNode()
            curr = curr.children[word[i]]
            if n < curr.shortest_len:
                curr.shortest_len = n
                curr.index = idx

    def search(self, word: str) -> int:
        curr, n = self.root, len(word)
        for i in range(n - 1, -1, -1):
            if word[i] not in curr.children:
                return curr.index
            curr = curr.children[word[i]]
        
        return curr.index

class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        root = Trie()
        
        for i, word in enumerate(wordsContainer):
            curr = root
            curr.insert(word, i)
        

        ans = [-1] * len(wordsQuery)

        for i, word in enumerate(wordsQuery):
            curr = root
            ans[i] = curr.search(word)

        return ans