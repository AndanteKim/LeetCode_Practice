class Solution:
    def concatenatedBinary(self, n: int) -> int:
        ans, bin_con = 0, ""
        MOD = 10 ** 9 + 7
        for i in range(1, n + 1):
            curr = str(bin(i)[2:])
            ans <<= len(curr)
            ans = (ans + i) % MOD

        return ans