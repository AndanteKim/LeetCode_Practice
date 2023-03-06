class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        n, ans = len(nums), 0
        stack = []
        
        for right in range(n + 1):
            while stack and (right == n or nums[stack[-1]] >= nums[right]):
                mid = stack.pop()
                left = -1 if not stack else stack[-1]
                ans -= nums[mid] * (mid - left) * (right - mid)
            stack.append(right)
            
        stack.clear()
        for right in range(n + 1):
            while stack and (right == n or nums[stack[-1]] <= nums[right]):
                mid = stack.pop()
                left = -1 if not stack else stack[-1]
                ans += nums[mid] * (mid - left) * (right - mid)
            stack.append(right)
        return ans