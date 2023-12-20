class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        prices.sort(reverse = True)
        change = money - prices.pop() - prices.pop()
        return money if change < 0 else change