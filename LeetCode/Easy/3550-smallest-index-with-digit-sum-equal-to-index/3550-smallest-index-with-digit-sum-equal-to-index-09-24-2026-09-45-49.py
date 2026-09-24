class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i, num in enumerate(nums):
            curr = 0
            while num > 0:
                curr += num % 10
                num //= 10
            
            if i == curr:
                return i

        return -1