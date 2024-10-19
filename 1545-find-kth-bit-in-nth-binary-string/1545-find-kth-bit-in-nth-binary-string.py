class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        @lru_cache(maxsize = None)
        def recursive(i: int) -> int:
            # Base case
            if i <= 1:
                return "0"
            
            half = recursive(i - 1)
            mid = '1'
            rest = "".join(['1' if i == '0' else '0' for i in half][::-1])
            return half + mid + rest
        
        return recursive(n)[k - 1]