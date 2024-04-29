class Solution:
    def maxNumber(self, n: int) -> int:
        
        return 2 ** int(log2(n)) - 1