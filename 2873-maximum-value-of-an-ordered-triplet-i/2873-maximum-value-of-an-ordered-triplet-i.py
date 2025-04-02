class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)

        for k in range(2, n):
            max_prefix = nums[0]
            for j in range(1, k):
                ans = max(ans, (max_prefix - nums[j]) * nums[k])
                max_prefix = max(max_prefix, nums[j])

        return ans