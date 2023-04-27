class Solution:
    def halveArray(self, nums: List[int]) -> int:
        
        total = sum(nums)
        target, ans = total / 2, 0
        nums = [-num for num in nums]
        heapify(nums)
        
        while total > target:
            curr = heappop(nums)
            total += curr
            heappush(nums, curr / 2)
            total -= curr / 2
            ans += 1
        
        return ans