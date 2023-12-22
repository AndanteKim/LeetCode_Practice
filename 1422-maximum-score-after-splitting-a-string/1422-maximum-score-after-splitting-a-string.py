class Solution:
    def maxScore(self, s: str) -> int:
        ans, left, right = 0, 1 if s[0] == '0' else 0, s.count('1') - 1 if s[0] == '1' else s.count('1')
        ans = max(ans, left + right)
        
        for i in range(1, len(s) - 1):
            if s[i] == '0':
                left += 1
            else:
                right -= 1
            ans = max(ans, left + right)
        return ans