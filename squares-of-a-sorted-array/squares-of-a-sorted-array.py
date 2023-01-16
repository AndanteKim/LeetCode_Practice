class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        nums.sort(key = lambda x: abs(x)**2)
        return [num ** 2 for num in nums]