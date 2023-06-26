class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        rob_plus_one = 0
        rob_next = nums[n - 1]
        
        for i in range(n - 2, -1, -1):
            current = max(rob_next, rob_plus_one + nums[i])
            rob_plus_one = rob_next;
            rob_next = current
        return rob_next