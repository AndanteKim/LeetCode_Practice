class Solution:
    def hammingWeight(self, n: int) -> int:
        steps = 0
        while (n > 0):
            steps += n & 1
            n = n >> 1
        
        return steps