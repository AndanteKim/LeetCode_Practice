class Solution:
    def maximumLengthOfRanges(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left, right = [0] * n, [0] * n
        idx_stack = []
        
        # Calculate left boundaries
        for curr_idx in range(n):
            while idx_stack and nums[idx_stack[-1]] < nums[curr_idx]:
                idx_stack.pop()
            left[curr_idx] = -1 if not idx_stack else idx_stack[-1]
            idx_stack.append(curr_idx)
            
        # Clear the stack for reuse
        idx_stack.clear()
        
        # Calculate right boundaries
        for curr_idx in range(n - 1, -1, -1):
            while idx_stack and nums[idx_stack[-1]] < nums[curr_idx]:
                idx_stack.pop()
            right[curr_idx] = n if not idx_stack else idx_stack[-1]
            idx_stack.append(curr_idx)
        
        # Calculate the maximal range for each element
        ans = [0] * n
        for curr_idx in range(n):
            ans[curr_idx] = right[curr_idx] - left[curr_idx] - 1
        
        return ans