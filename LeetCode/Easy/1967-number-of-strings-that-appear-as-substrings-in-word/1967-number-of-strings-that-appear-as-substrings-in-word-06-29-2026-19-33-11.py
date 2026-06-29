class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        ans = 0
        for p in patterns:
            if p in word:
                ans += 1
        
        return ans