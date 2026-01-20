class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n

        for i in range(n):
            exist = False
            for num in range(nums[i]):
                if num | (num + 1) == nums[i]:
                    ans[i] = num
                    exist = True
                    break
            
            if not exist:
                ans[i] = -1

        return ans