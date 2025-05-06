class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        n = len(nums)

        # Build the final value on the first iteration
        for i in range(n):
            nums[i] += 1000 * (nums[nums[i]] % 1000)

        # Modified to final value on the second iteration
        for i in range(n):
            nums[i] //= 1000
        
        return nums