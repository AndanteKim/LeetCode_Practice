class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        ans = left = i = 0

        while i < n:
            if s[i] == '(':
                left += 1
                i += 1
            else:
                if left > 0:
                    left -= 1
                else:
                    ans += 1
                
                if i < n - 1 and s[i + 1] == ')':
                    i += 2
                else:
                    ans += 1
                    i += 1
        
        ans += left * 2
        return ans