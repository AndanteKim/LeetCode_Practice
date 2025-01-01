class Solution:
    def maxScore(self, s: str) -> int:
        n = len(s)
        left_zeros, right_ones = 1 if s[0] == '0' else 0, s.count('1') - 1 if s[0] == '1' else s.count('1')
        ans = left_zeros + right_ones

        for i in range(1, n - 1):
            if s[i] == '0':
                left_zeros += 1
            
            if s[i] == '1':
                right_ones -= 1
            
            ans = max(ans, left_zeros + right_ones)

        return ans
        

