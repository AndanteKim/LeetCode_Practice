class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums.sort()
        return (nums.pop() - 1) * (nums.pop() - 1)