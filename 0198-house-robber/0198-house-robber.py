class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        max_rob = [0] * (n + 1)
        
        max_rob[n], max_rob[n - 1] = 0, nums[n - 1]
        
        for i in range(n - 2, -1, -1):
            max_rob[i] = max(max_rob[i + 1], max_rob[i + 2] + nums[i])
        return max_rob[0]