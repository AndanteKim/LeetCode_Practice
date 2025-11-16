class Solution:
    def numSub(self, s: str) -> int:
        n, count1 = len(s), 0
        ans, mod = 0, 10 ** 9 + 7

        for c in s:
            if c == '1':
                count1 += 1
            else:
                ans = (ans + ((count1 * (count1 + 1)) >> 1)) % mod
                count1 = 0

        if count1 > 0:
            ans = (ans + ((count1 * (count1 + 1)) >> 1)) % mod

        return ans