class Solution:
    def trap(self, height: List[int]) -> int:
        ans, size = 0, len(height)
        left_max, right_max = [0] * size, [0] * size
        
        # Search the left part for max bar size
        left_max[0] = height[0]
        for i in range(1, size):
            left_max[i] = max(left_max[i - 1], height[i])
            
        # Search the right side for max bar size
        right_max[-1] = height[-1]
        for i in range(size - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], height[i])
            
        # Find the overlap of both sides
        for i in range(1, size - 1):
            ans += min(left_max[i], right_max[i]) - height[i]
        
        return ans