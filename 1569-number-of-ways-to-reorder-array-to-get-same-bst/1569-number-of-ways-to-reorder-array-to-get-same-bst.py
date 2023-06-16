class Solution:
    def dfs(self, nums: List[int], mod: int) -> int:
        m = len(nums)
        if m < 3:
            return 1
        left_nodes = [a for a in nums if a < nums[0]]
        right_nodes = [a  for a in nums if a > nums[0]]
        return self.dfs(left_nodes, mod) * self.dfs(right_nodes, mod) * comb(m - 1, len(left_nodes)) % mod
    
    def numOfWays(self, nums: List[int]) -> int:
        mod = 10 ** 9 + 7
        return (self.dfs(nums, mod) - 1) % mod