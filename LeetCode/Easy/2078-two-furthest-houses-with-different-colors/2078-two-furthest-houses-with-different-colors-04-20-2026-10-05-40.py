class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        ans, n = 0, len(colors)
        for i in range(n - 1):
            for j in range(n):
                if colors[i] != colors[j]:
                    ans = max(ans, j - i)
        
        return ans