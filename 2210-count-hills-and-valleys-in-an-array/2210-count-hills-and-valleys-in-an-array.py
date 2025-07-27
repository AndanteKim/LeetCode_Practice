class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        i = 1

        while i < n - 1:
            j, k = i - 1, i + 1
            
            while k < n - 1 and nums[i] == nums[k]:
                k += 1

            if nums[j] < nums[i] and nums[i] > nums[k]:
                ans += 1
            elif nums[j] > nums[i] and nums[i] < nums[k]:
                ans += 1

            i = k

        return ans
