class Solution:
    def check(self, nums: List[int]) -> bool:
        if len(nums) <= 1:
            return True

        n, inversion = len(nums), 0

        # For every pair, count the number of inversions
        for i in range(1, n):
            if nums[i - 1] > nums[i]:
                inversion += 1
        
        # Also check between the last and the first element due to rotation
        if nums[0] < nums[n - 1]:
            inversion += 1

        return True if inversion <= 1 else False