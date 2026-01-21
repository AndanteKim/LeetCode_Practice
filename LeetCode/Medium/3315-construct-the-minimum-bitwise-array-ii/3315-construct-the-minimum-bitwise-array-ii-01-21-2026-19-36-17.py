class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n

        for i in range(n):
            curr, num, d = -1, nums[i], 1

            while (num & d) != 0:
                curr = num - d
                d <<= 1

            ans[i] = curr            

        return ans