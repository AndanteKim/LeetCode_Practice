class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        def sum_up(i: int, j: int) -> int:
            return sum(grid[k][j] for k in range(i + 1))
        
        def sum_left(i: int, j: int) -> int:
            return sum(grid[i][k] for k in range(j + 1))
        
        m, n = len(grid), len(grid[0])
        ans, curr_sum, left_bound = 0, 0, n - 1

        for i in range(m):
            curr_sum += sum_left(i, left_bound)

            while curr_sum > k:
                curr_sum -= sum_up(i, left_bound)
                left_bound -= 1
            
            ans += left_bound + 1

        return ans

        