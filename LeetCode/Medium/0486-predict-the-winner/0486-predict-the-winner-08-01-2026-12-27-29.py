class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)

        def max_diff(left: int, right: int) -> int:
            if left == right:
                return nums[left]

            score_left = nums[left] - max_diff(left + 1, right)
            score_right = nums[right] - max_diff(left, right - 1)

            return max(score_left, score_right)
        
        return max_diff(0, n - 1) >= 0