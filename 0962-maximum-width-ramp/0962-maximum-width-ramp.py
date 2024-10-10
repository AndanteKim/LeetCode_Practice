class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        indices_stack = []
        
        # Fill the stack with indices in increasing order of their values
        for i in range(n):
            if not indices_stack or nums[indices_stack[-1]] > nums[i]:
                indices_stack.append(i)
            
        max_width = 0
        
        # Traverse the array from the end to the start
        for j in range(n - 1, -1, -1):
            while indices_stack and nums[indices_stack[-1]] <= nums[j]:
                # Pop the index since it's already processed.
                max_width = max(max_width, j - indices_stack.pop())
                
        return max_width