class Solution:
    def binaryGap(self, n: int) -> int:
        prev, num, i = -1, n, 0
        ans = 0

        while num > 0:
            if num % 2:
                if prev != -1:
                    ans = max(ans, i - prev)
                prev = i
            i += 1 
            num >>= 1

        return ans