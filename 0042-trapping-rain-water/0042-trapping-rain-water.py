class Solution:
    def trap(self, height: List[int]) -> int:
        ans, stack = 0, []
        
        for curr in range(len(height)):
            while stack and height[curr] > height[stack[-1]]:
                right = stack.pop()
                if not stack:
                    break
                dist = curr - stack[-1] - 1
                bounded_height = min(height[curr], height[stack[-1]]) - height[right]
                ans += dist * bounded_height
            
            stack.append(curr)
        
        return ans