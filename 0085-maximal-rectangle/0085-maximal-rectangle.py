class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        
        m, n = len(matrix), len(matrix[0])
        
        # Initialize left and right as the leftmost and rightmosot boundary possible for each
        left, right = [0] * n, [n] * n
        height = [0] * n
        
        max_area = 0
        
        for i in range(m):
            curr_left, curr_right = 0, n
            # update height
            for j in range(n):
                if matrix[i][j] == '1':
                    height[j] += 1
                else:
                    height[j] = 0
                    
            # update left
            for j in range(n):
                if matrix[i][j] == '1':
                    left[j] = max(left[j], curr_left)
                else:
                    left[j] = 0
                    curr_left = j + 1
            
            # update right
            for j in range(n - 1, -1, -1):
                if matrix[i][j] == '1':
                    right[j] = min(right[j], curr_right)
                else:
                    right[j] = n
                    curr_right = j
            
            # update the area
            for j in range(n):
                max_area = max(max_area, height[j] * (right[j] - left[j]))
        
        return max_area