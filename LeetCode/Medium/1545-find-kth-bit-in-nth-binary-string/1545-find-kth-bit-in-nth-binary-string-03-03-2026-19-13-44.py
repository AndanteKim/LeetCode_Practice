class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n == 1:
            return "0"
        
        curr = "0"
        for i in range(n):
            curr = curr + "1" + "".join(['1' if c == '0' else '0' for c in curr][::-1])

        return curr[k - 1]