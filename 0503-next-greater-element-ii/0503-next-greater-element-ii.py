class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n, stack = len(nums), []
        ans = [-1] * n
        
        for i in range(2 * n):
            while stack and nums[i % n] > nums[stack[-1] % n]:
                ans[stack.pop() % n] = nums[i % n]
            stack.append(i)
            
        return ans