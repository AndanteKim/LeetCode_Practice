class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        length = len(nums)
        result = [0] * length
        left, right = 0, length - 1
        
        for i in range(length-1, -1, -1):
            if abs(nums[left]) < abs(nums[right]):
                square = nums[right]
                right -= 1
            else:
                square = nums[left]
                left += 1
            result[i] = square ** 2
        return result