class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        max_price, ans, count = max(prices), money, 0
        count_sorting = [0] * (max_price + 1)
        for price in prices:
            count_sorting[price] += 1
            
        for price in range(max_price + 1):
            if count >= 2 or price > ans:
                break
            
            while count < 2 and count_sorting[price] > 0:
                ans -= price
                count += 1
                count_sorting[price] -= 1
        
        return money if count != 2 or ans < 0 else ans 
        