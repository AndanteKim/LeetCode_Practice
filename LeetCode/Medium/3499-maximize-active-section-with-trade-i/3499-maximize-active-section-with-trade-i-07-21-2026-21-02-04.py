class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        cnt1 = s.count('1')

        n, i = len(s), 0

        ans, prev = 0, float('-inf')
        
        while i < n:
            start = i

            while i < n and s[i] == s[start]:
                i += 1
            
            if s[start] == '0':
                curr = i - start
                ans = max(ans, prev + curr)
                prev = curr
        
        return cnt1 + ans