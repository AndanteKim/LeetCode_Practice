class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        ans, sorted_heights = 0, sorted(heights)
        
        for i in range(len(heights)):
            if sorted_heights[i] != heights[i]:
                ans += 1
                
        return ans