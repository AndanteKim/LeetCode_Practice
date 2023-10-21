class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        heap = [(-nums[0], 0)]
        ans = nums[0]
        
        for i in range(1, len(nums)):
            while i - heap[0][1] > k:
                heappop(heap)
            
            curr = max(0, -heap[0][0]) + nums[i]
            ans = max(ans, curr)
            heappush(heap, (-curr, i))
        
        return ans