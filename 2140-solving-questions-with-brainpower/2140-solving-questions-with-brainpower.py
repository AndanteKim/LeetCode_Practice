class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        def dp(i: int) -> int:
            if i >= n:
                return 0

            if memo[i] != -1:
                return memo[i]

            max_points = max(questions[i][0] + dp(i + questions[i][1] + 1), dp(i + 1))
            memo[i] = max_points
            return max_points
        
        n = len(questions)
        memo = [-1] * n
        return dp(0)