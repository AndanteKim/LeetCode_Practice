class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        left, right, up, down = 0, n - 1, 0, n - 1
        i = 1
        while i <= n ** 2:
            for col in range(left, right + 1):
                ans[up][col] = i
                i += 1
            
            for row in range(up + 1, down + 1):
                ans[row][right] = i
                i += 1
            
            if up != down:
                for col in range(right - 1, left - 1, -1):
                    ans[down][col] = i
                    i += 1
            
            if left != right:
                for row in range(down - 1, left, -1):
                    ans[row][left] = i
                    i += 1
            
            up += 1
            down -= 1
            left += 1
            right -= 1
        return ans