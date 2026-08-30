class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)

        min_elem, max_elem = float('inf'), float('-inf')
        min_idx, max_idx = -1, -1

        for i, num in enumerate(nums):
            if num < min_elem:
                min_idx, min_elem = i, num
            
            if num > max_elem:
                max_idx, max_elem = i, num
        
        ans, n = float('inf'), len(nums)
        # 1st case: front, end edges
        ans = min(ans, n - abs(min_idx - max_idx) + 1)

        # 2nd case: only front edges
        ans = min(ans, max(min_idx + 1, max_idx + 1))

        # 3rd case: only end edges
        ans = min(ans, max(n - min_idx, n - max_idx))

        return ans