class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return nums[0]
        
        rob_next, rob_next_plus_one = nums[0], 0
        
        for i in range(1, n):
            current = max(rob_next, rob_next_plus_one + nums[i])
            rob_next_plus_one = rob_next
            rob_next = current
        
        return rob_next