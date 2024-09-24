class TrieNode:
    def __init__(self):
        self.is_end = False
        self.children = dict()
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, s:str) -> None:
        curr = self.root
        for c in s:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.is_end = True
    
    def search_longest_prefix(self, s: str) -> int:
        length, curr = 0, self.root
        
        for c in s:
            if c not in curr.children:
                break
            curr = curr.children[c]
            length += 1
        return length

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        t1, t2 = Trie(), Trie()
        
        str1, str2 = [str(n1) for n1 in arr1], [str(n2) for n2 in arr2]
        for s1 in str1:
            t1.insert(s1)
            
        for s2 in str2:
            t2.insert(s2)
        
        ans = 0
        for s1 in str1:
            ans = max(ans, t2.search_longest_prefix(s1))
            
        for s2 in str2:
            ans = max(ans, t1.search_longest_prefix(s2))
        
        return ans