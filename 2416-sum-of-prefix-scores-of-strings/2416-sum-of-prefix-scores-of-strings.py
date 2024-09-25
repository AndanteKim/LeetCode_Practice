class TrieNode:
    def __init__(self):
        self.prefix_length = 0
        self.children = dict()
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, s: str) -> None:
        curr = self.root
        
        for c in s:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
            curr.prefix_length += 1
            
            
    def search(self, s: str) -> int:
        curr, prefix_sum = self.root, 0
        
        for c in s:
            if c not in curr.children:
                break
            curr = curr.children[c]
            prefix_sum += curr.prefix_length
        
        return prefix_sum

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        trie, n = Trie(), len(words)
        
        for word in words:
            trie.insert(word)
            
        ans = [0] * n
        for i, word in enumerate(words):
            ans[i] = trie.search(word)
            
        return ans