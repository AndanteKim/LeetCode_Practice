class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        # Get the maximum area in a histogram given its heights
        def find_max_rec(heights: List[int]) -> int:
            st, max_area = [-1], 0

            for i in range(n):

                while st[-1] != -1 and heights[st[-1]] >= heights[i]:
                    max_area = max(
                        max_area, heights[st.pop()] * (i - st[-1] - 1)
                    )

                st.append(i)
            
            while st[-1] != -1:
                max_area = max(
                    max_area, heights[st.pop()] * (n - st[-1] - 1)
                )

            return max_area
        
        if not matrix:
            return 0

        ans, m, n = 0, len(matrix), len(matrix[0])
        dp = [0] * n

        for i in range(m):
            for j in range(n):
                # Update the state of this row's histogram using the last row's histogram
                # by keeping track of the number of consecutive ones
                dp[j] = dp[j] + 1 if matrix[i][j] == '1' else 0

            # Update ans with the maximum area from this row's histogram
            ans = max(ans, find_max_rec(dp))

        return ans   
            