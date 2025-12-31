class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n

        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    ans[i] += 1
            
            for j in range(i + 1, n):
                if nums[i] > nums[j]:
                    ans[i] += 1

        return ans