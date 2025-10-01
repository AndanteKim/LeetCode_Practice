class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans, remain, empty = 0, numBottles, 0

        while remain > 0:
            ans += remain
            empty += remain
            remain = empty // numExchange
            empty -= (remain * numExchange)

        return ans