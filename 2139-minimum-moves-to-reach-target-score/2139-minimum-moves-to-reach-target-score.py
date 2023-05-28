class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        ans = 0
        
        while target > 1 and maxDoubles > 0:
            ans += 1 + target % 2
            maxDoubles -= 1
            target >>= 1
        
        return target - 1 + ans
        