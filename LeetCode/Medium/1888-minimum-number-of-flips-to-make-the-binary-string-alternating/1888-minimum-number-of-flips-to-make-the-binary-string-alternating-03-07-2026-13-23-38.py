class Solution:
    def minFlips(self, s: str) -> int:
        start = 48  # 48 = '0'
        flip0, n = 0, len(s)

        for c in s:
            if ord(c) != start:
                flip0 += 1
            start ^= 1
        
        ans = min(flip0, n - flip0)   
        # If n is even, no need to utilize sliding window
        if not n & 1:
            return ans

        start = 48
        for c in s:
            if start != ord(c):
                flip0 -= 1
                ans = min(ans, flip0)
            else:
                flip0 += 1
                ans = min(ans, n - flip0)
            start ^= 1

        return ans
