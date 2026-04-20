class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        ans, n = 0, len(colors)

        for i in range(n):
            if colors[i] != colors[0]:
                ans = max(ans, i)
            
            if colors[i] != colors[-1]:
                ans = max(ans, n - 1 - i)
            
        return ans