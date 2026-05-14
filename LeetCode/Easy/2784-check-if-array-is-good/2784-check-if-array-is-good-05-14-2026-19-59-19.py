class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = len(nums)
        count = [0] * n

        for num in nums:
            if num >= n:
                return False

            if num < n - 1 and count[num] > 0:
                return False
            
            if num == n - 1 and count[num] > 1:
                return False
            
            count[num] += 1

        return True