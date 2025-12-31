class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # Iterate over each of the elemetns in the original array
        for i in range(len(nums)):
            new_idx = abs(nums[i]) - 1

            if nums[new_idx] > 0:
                nums[new_idx] *= -1

        ans = []

        for i in range(1, len(nums) + 1):
            if nums[i - 1] > 0:
                ans.append(i)

        return ans