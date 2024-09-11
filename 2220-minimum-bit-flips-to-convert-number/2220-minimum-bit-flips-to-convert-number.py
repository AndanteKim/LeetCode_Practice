class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        convert = 0
        while start > 0 or goal > 0:
            if goal & 1 != start & 1:
                convert += 1
            goal >>= 1
            start >>= 1
        
        return convert