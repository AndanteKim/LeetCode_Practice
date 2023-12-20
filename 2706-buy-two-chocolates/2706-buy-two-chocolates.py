class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        minimum = min(prices[0], prices[1])
        second_minimum = max(prices[0], prices[1])
        
        for i in range(2, len(prices)):
            if prices[i] < minimum:
                second_minimum = minimum
                minimum = prices[i]
            elif prices[i] < second_minimum:
                second_minimum = prices[i]
        
        min_cost = minimum + second_minimum
        
        return money - min_cost if min_cost <= money else money