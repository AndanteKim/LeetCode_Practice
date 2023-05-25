class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        heap = []
        
        for num in nums:
            heappush(heap, num)
        
        while k > 0:
            elem = heappop(heap)
            heappush(heap, -elem)
            k -= 1
        
        return sum(heap)