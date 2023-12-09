class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        last_pos = n - 1
        
        for i in range(n - 1, -1, -1):
            if nums[i] + i >= last_pos:
                last_pos = i
        
        return last_pos == 0