class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        zeros, n, ans = s.count('0'), len(s), ''
        ones = n - zeros
        
        if ones > 1:
            ans += '1' * (ones - 1)
        ans += '0' * zeros
        
        return ans + '1'