class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        zero_cnt = 0
        for c in s:
            if c == '0':
                zero_cnt += 1
        ans = zero_cnt
        
        for c in s:
            if c == '0':
                zero_cnt -= 1
                ans = min(ans, zero_cnt)
            else:
                zero_cnt += 1
        
        return ans