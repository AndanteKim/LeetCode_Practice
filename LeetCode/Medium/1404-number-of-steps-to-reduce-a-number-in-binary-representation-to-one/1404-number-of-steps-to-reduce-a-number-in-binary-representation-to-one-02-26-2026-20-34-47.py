class Solution:
    def numSteps(self, s: str) -> int:
        dec, n = 0, len(s)

        for i in range(n):
            dec += (ord(s[i]) - 48) * (1 << (n - 1 - i))

        ans = 0
        while dec > 1:
            if dec % 2 == 0:
                dec >>= 1
            else:
                dec += 1
            ans += 1

        return ans