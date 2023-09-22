class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
        stack, ans = [], 0
        
        for i in range(len(nums)):
            # keep popping elements from the stack
            # until the current element becomes greater than the top element
            while stack and nums[i] < nums[stack[-1]]:
                # The diff between the current index and the stack top would be the subarray size.
                # which is equal to the number of subarrays
                ans += (i - stack[-1])
                stack.pop()
            stack.append(i)
        
        # For all remaining elements, the last element will be considered as the right endpoint
        while stack:
            ans += len(nums) - stack[-1]
            stack.pop()
                
        return ans