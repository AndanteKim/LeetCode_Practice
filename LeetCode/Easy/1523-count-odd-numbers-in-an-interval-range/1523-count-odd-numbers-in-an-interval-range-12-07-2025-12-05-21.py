class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (((high - low) >> 1) + 1) if low % 2 and high % 2 else (high - low + 1) >> 1