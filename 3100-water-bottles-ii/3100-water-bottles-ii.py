class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        ans, full, empty = 0, numBottles, 0

        while full > 0:
            ans += full
            empty += full
            full = 0
            while empty >= numExchange:
                full += 1
                empty -= numExchange
                numExchange += 1
        
        return ans