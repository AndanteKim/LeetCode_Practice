class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        indices = [i for i in range(n)]
        
        # Sort indices based on corresponding values in nums and ensure stability
        indices.sort(key = lambda i: (nums[i], i))
        
        # Minimum index encountered so far
        min_idx, max_width = n, 0
        
        # Calculate maximum width ramp
        for i in indices:
            max_width = max(max_width, i - min_idx)
            min_idx = min(min_idx, i)
            
        return max_width