class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        colors, ans = [0] * 3, []
        
        for num in nums:
            colors[num] += 1
            
        color = 0
        for i in range(len(nums)):
            while colors[color] == 0:
                color += 1
            
            nums[i] = color
            colors[color] -= 1