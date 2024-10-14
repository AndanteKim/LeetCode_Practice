class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        pq = []
        for num in nums:
            heappush(pq, -num)
        
        ans = 0
        while pq and k > 0:
            num = heappop(pq)
            num *= -1
            ans += num
            num = num // 3 + 1 if (num // 3) != num / 3 else num // 3
            k -= 1
            if num > 0:
                heappush(pq, -num)
                
        return ans