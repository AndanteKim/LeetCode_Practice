class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        # Find the maximum value in nums
        max_val, n = max(nums), len(nums)

        # Create a frequency array based on the maximum value
        freq, distinct_cnt = [0] * (max_val + 1), 0
        ans = [0] * (n - k + 1)

        for pos in range(n):
            # Add new number
            freq[nums[pos]] += 1

            if freq[nums[pos]] == 1:
                distinct_cnt += 1

            # Remove old number
            if pos >= k:
                freq[nums[pos - k]] -= 1
                if freq[nums[pos - k]] == 0:
                    distinct_cnt -= 1
            
            # Store result for complete window
            if pos + 1 >= k:
                ans[pos + 1 - k] = distinct_cnt

        return ans

