class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        heapify(nums)
        
        for _ in range(k):
            heappush(nums, heappop(nums) + 1)
        
        MOD, ans = 1_000_000_007, 1
        
        for num in nums:
            ans = (ans * num) % MOD
            
        return ans
        