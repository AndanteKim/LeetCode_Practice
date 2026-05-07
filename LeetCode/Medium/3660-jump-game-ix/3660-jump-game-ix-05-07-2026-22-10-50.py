class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        def process(r: int, right_min: float, right_max: float) -> None:
            p_max, pivot_idx = prev_max[r]
            curr_max = p_max if p_max <= right_min else right_max

            next_right_min = min(p_max, right_min)
            for i in range(pivot_idx, r + 1):
                ans[i] = curr_max
                next_right_min = min(next_right_min, nums[i])
            
            if pivot_idx == 0:
                return

            process(pivot_idx - 1 , next_right_min, curr_max)

        
        n = len(nums)
        ans = [0] * n
        # [value, index]
        prev_max = [(0, 0)] * n
        prev = (float('-inf'), -1)

        for i, val in enumerate(nums):
            if val > prev[0]:
                prev = (val, i)
            prev_max[i] = prev

        process(n - 1, float('inf'), 0)

        return ans