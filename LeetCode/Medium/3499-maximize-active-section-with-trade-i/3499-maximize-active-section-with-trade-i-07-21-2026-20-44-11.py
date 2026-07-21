class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        n = len(s)
        cnt1 = s.count('1')
        zero_blocks = []
        i = 0

        while i < n:
            start = i

            while i < n and s[i] == s[start]:
                i += 1
            
            if s[start] == "0":
                zero_blocks.append(i - start)
            
        m = len(zero_blocks)

        if m < 2:
            return cnt1
        
        ans = 0

        for i in range(m - 1):
            ans = max(ans , zero_blocks[i] + zero_blocks[i + 1])
        
        return cnt1 + ans