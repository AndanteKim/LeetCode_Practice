class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        ans = 0

        # Capture each bit that is set in any of the elements
        for num in nums:
            ans |= num

        # Multiply by the number of subset XOR totals that will have each bit set
        return ans << (len(nums) - 1)