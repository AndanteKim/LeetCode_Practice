class Solution:
    def lps(self, left: int, right: int, s: str) -> int:
        if (left, right) in self.memo:
            return self.memo[(left, right)]
        if left > right:
            return 0
        if left == right:
            return 1
        
        if s[left] == s[right]:
            self.memo[(left, right)] = self.lps(left + 1, right - 1, s) + 2
        else:
            self.memo[(left, right)] = max(self.lps(left, right - 1, s), self.lps(left + 1, right, s))
        return self.memo[(left, right)]
    
    def longestPalindromeSubseq(self, s: str) -> int:
        self.memo = dict()
        return self.lps(0, len(s) - 1, s)