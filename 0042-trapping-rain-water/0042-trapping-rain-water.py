class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        
        ans, n = 0, len(height)
        left_max, right_max = [0] * n, [0] * n
        left_max[0], right_max[-1] = height[0], height[-1]
        
        # Find the left side of area
        for i in range(1, n):
            left_max[i] = max(height[i], left_max[i - 1])
        
        # Find the right side of area
        for i in range(n - 2, -1, -1):
            right_max[i] = max(height[i], right_max[i + 1])
        
        for i in range(1, n - 1):
            ans += min(left_max[i], right_max[i]) - height[i]
            
        return ans