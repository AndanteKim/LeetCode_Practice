class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True

        if len(nums) == 2:
            return nums[0] % 2 != nums[1] % 2

        n = len(nums)
        for i in range(1, n - 1):
            if (nums[i - 1] % 2 == nums[i] % 2) or (nums[i] % 2 == nums[i + 1] % 2):
                return False
        
        return True