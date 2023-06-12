class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()
        left, right, n = 0, price[-1] - price[0], len(price)
        
        while left < right:
            mid = (left + right + 1) >> 1
            cnt, j = 1, 0
            for i in range(1, n):
                if price[i] - price[j] >= mid:
                    cnt += 1
                    j = i
            if cnt >= k:
                left = mid
            else:
                right = mid - 1
        
        return left
            