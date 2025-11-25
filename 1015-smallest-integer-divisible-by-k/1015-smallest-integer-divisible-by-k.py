class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        mod = 0

        for length_n in range(1, k + 1):
            mod = (mod * 10 + 1) % k

            if mod == 0:
                return length_n

        return -1