class Solution:
    def minOperations(self, s: str) -> int:
        start0, start1 = 0, 1
        change0, change1 = 0, 0

        for c in s:
            change0 += start0 ^ (ord(c) - 48)
            start0 ^= 1
            change1 += start1 ^ (ord(c) - 48)
            start1 ^= 1

        return min(change0, change1)