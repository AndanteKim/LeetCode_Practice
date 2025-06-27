class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        total, cnt = 0, 0
        bits = k.bit_length()

        for i, ch in enumerate(s[::-1]):
            if ch == '1':
                if i < bits and total + (1 << i) <= k:
                    total += (1 << i)
                    cnt += 1
            else:
                cnt += 1
        
        return cnt