class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        ans, temp = nums[:], nums[:]
        n = len(nums)
        for i in range(n):
            temp[i] = nums[i]
            ans[i] = nums[temp[i]]

        return ans