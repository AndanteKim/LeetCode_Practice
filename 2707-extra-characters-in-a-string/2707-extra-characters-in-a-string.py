class TrieNode:
    def __init__(self):
        self.children = dict()
        self.is_word = False
        
class Solution:
    def buildTrie(self, dictionary: List[str]) -> bool:
        root = TrieNode()
        
        for word in dictionary:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.is_word = True
        
        return root
    
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n, root = len(s), self.buildTrie(dictionary)
        
        @lru_cache(maxsize = None)
        def dp(start: int) -> int:
            if start == n:
                return 0
        
            # To count this character as a left over character
            # move to index 'start + 1'
            ans = dp(start + 1) + 1
            node = root
            for end in range(start, n):
                if s[end] not in node.children:
                    break
                node = node.children[s[end]]
                if node.is_word:
                    ans = min(ans, dp(end + 1))
            return ans
        
        return dp(0)