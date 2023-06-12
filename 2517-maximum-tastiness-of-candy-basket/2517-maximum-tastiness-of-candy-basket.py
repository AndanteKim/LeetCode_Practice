class Solution:
    def check(self, x: int, price: List[int], k: int, n: int) -> bool:
        last, cnt, i = price[0], 1, 1
        while cnt < k and i < n:
            if price[i] - last >= x:
                last, cnt = price[i], cnt + 1
            i += 1
        return cnt == k

    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()
        
        left, right, n = 0, 10 ** 9, len(price)
        
        while left < right:
            mid = (left + right) >> 1
            if self.check(mid, price, k, n):
                left = mid + 1
            else:
                right = mid
        
        return left - 1
            
            
                