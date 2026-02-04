class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        n, ans = len(nums), float('-inf')
        i = 0

        while i < n:
            j, res = i + 1, 0

            # First segment: increasing segment:
            while j < n and nums[j - 1] < nums[j]:
                j += 1
            p = j - 1

            if p == i:
                i += 1
                continue
            
            # Second segment: decreasing segment
            res += nums[p] + nums[p - 1]
            while j < n and nums[j - 1] > nums[j]:
                res += nums[j]
                j += 1
            q = j - 1
        
            if q == p or q == n - 1 or (j < n and nums[j] <= nums[q]):
                i = q
                continue
            
            # Third segment: increasing segment
            res += nums[q + 1]

            # Find the maximum sum of the third segment
            max_sum, curr_sum = 0, 0
            k = q + 2
            while k < n and nums[k] > nums[k - 1]:
                curr_sum += nums[k]
                max_sum = max(max_sum, curr_sum)
                k += 1
            res += max_sum

            # Find the maximum sum of the first segment
            max_sum, curr_sum = 0, 0
            for k in range(p - 2, i - 1, -1):
                curr_sum += nums[k]
                max_sum = max(max_sum, curr_sum)
            res += max_sum

            # Update answer
            ans = max(ans, res)
            i = q

        return ans