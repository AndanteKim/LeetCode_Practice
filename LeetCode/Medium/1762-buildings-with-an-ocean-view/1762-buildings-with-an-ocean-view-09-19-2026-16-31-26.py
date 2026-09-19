class Solution:
    def findBuildings(self, heights: list[int]) -> list[int]:
        ans = []

        for i, h in enumerate(heights):
            while ans and heights[ans[-1]] <= h:
                ans.pop()
            ans.append(i)
        
        return ans