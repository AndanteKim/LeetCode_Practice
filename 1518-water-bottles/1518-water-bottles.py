class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        # Mathematical formula
        return numBottles + ((numBottles - 1) // (numExchange - 1))