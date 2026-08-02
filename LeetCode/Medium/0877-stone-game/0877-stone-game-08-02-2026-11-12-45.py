class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        def dp(left: int, right: int) -> int:
            if left == right:
                return piles[left]

            if memo[left][right] != -1:
                return memo[left][right]

            max_left = piles[left] - dp(left + 1, right)
            max_right = piles[right] - dp(left, right - 1)

            memo[left][right] = max(max_left, max_right)
            return memo[left][right]


        n = len(piles)
        memo = [[-1] * (n + 1) for _ in range(n)]
        return dp(0, n - 1) > 0