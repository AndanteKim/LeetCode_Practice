class Solution:
    def monotone(self, heights: List[int]) -> int:
        stack, max_area = [-1], 0
        
        for i in range(len(heights)):
            while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
                max_area = max(max_area, heights[stack.pop()] * (i - stack[-1] - 1))
            stack.append(i)
        
        while stack[-1] != -1:
            max_area = max(max_area, heights[stack.pop()] * (len(heights) - stack[-1] - 1))

        return max_area
    
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        
        max_area, m, n = 0, len(matrix), len(matrix[0])
        dp = [0] * n
        for i in range(m):
            for j in range(n):
                # Update the state of this row's histogram using the last row's histogram
                # by keeping track of the number of consecutive ones
                dp[j] = dp[j] + 1 if matrix[i][j] == '1' else 0
            
            # update max_area with the maximum area from this row's historgram
            max_area = max(max_area, self.monotone(dp))
        return max_area