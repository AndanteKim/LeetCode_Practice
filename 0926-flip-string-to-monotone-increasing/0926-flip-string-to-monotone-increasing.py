class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        change_cnt = 0
        for c in s:
            if c == '0':
                change_cnt += 1
        ans = change_cnt
        
        for c in s:
            if c == '0':
                change_cnt -= 1
                ans = min(ans, change_cnt)
            else:
                change_cnt += 1
        
        return ans