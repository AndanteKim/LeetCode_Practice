class TrieNode:
    def __init__(self):
        self.children = dict()
        self.is_end = False
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.is_end = True    
        
        
    def startswith(self, word: str) -> str:
        curr, prefix = self.root, ""
        for c in word:
            if curr.is_end or len(curr.children) != 1 or c not in curr.children:
                break
            
            curr = curr.children[c]
            prefix += c
        
        return prefix
    
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        
        if len(strs) == 1:
            return strs[0]
        
        trie = Trie()
        for i in range(len(strs)):
            trie.insert(strs[i])
        
        return trie.startswith(strs[0])