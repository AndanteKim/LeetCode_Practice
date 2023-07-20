class TrieNode:
    def __init__(self):
        self.is_word = False
        self.children = dict()

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        root = TrieNode()
        
        for word in wordDict:
            curr = root
            for c in word:
                if c not in curr.children:
                    curr.children[c] = TrieNode()
                curr = curr.children[c]
            curr.is_word = True
        
        dp = [False] * len(s)
        for i in range(len(s)):
            if i == 0 or dp[i - 1]:
                curr = root
                for j in range(i, len(s)):
                    c = s[j]
                    if c not in curr.children:
                        break
                    curr = curr.children[c]
                    if curr.is_word:
                        dp[j] = True
        return dp[-1]