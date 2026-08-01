class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        def max_diff(left: int, right: int) -> int:
            if left == right:
                return nums[left]

            if memo[left][right] != -1:
                return memo[left][right]

            score_by_left = nums[left] - max_diff(left + 1, right)
            score_by_right = nums[right] - max_diff(left, right - 1)

            memo[left][right] = max(score_by_left, score_by_right)
            return memo[left][right]

        n = len(nums)
        memo = [[-1] * n for _ in range(n)]

        return max_diff(0, n - 1) >= 0