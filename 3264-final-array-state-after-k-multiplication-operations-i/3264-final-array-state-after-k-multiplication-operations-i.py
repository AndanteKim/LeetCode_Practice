class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        min_heap, n = [], len(nums)
        ans = [0] * n
        
        for i, num in enumerate(nums):
            heappush(min_heap, (num, i))
            
        for _ in range(k):
            num, idx = heappop(min_heap)
            heappush(min_heap, (num * multiplier, idx))
            
        while min_heap:
            num, i = heappop(min_heap)
            ans[i] = num
            
        return ans