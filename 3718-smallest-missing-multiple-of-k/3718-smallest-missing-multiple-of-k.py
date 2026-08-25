class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        nums, x = set(nums), k

        while x <= 1000:
            if x not in nums:
                return x
            x += k

        return -1