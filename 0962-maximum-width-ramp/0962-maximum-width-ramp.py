class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        right_max = [0] * n
        
        # Fill right_max array with the maximum values from the right
        right_max[-1] = nums[-1]
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], nums[i])
            
        left, right = 0, 0
        max_width = 0
        
        # Traverse the array using left and right pointers
        while right < n:
            # Move left pointer forward if current left exceeds right_max
            while left < right and nums[left] > right_max[right]:
                left += 1
                
            max_width = max(max_width, right - left)
            right += 1
        
        return max_width