class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        if target == 1:
            return 0
        
        if maxDoubles == 0:
            return target - 1
        
        if target & 1:
            return 1 + self.minMoves(target - 1, maxDoubles)
        else:
            return 1 + self.minMoves(target // 2, maxDoubles - 1)