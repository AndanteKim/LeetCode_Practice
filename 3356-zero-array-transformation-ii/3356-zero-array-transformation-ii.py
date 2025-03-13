class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        left, right = 0, len(queries)
        
        # Zero array isn't formed after all queries are processed
        if not self.can_form_zero_array(nums, queries, right):
            return -1

        # Binary Search
        while left <= right:
            mid = left + ((right - left) >> 1)

            if self.can_form_zero_array(nums, queries, mid):
                right = mid - 1
            else:
                left = mid + 1
        
        # Return earliest query that zero array can be formed
        return left

    def can_form_zero_array(self, nums: List[int], queries: List[List[int]], k: int) -> bool:
        n = len(nums)
        total, diff_arr = 0, [0] * (n + 1)

        # Process query
        for q_idx in range(k):
            start, end, val = queries[q_idx]

            # Process start and end of range
            diff_arr[start] += val
            diff_arr[end + 1] -= val

        # Check if zero array can be formed
        for n_idx in range(n):
            total += diff_arr[n_idx]
            if total < nums[n_idx]:
                return False

        return True 