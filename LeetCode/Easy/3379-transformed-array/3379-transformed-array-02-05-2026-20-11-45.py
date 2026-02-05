class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n

        for i in range(n):
            if nums[i] != 0:
                ans[i] = nums[(i + nums[i]) % n]
            else:
                ans[i] = nums[i]

        return ans