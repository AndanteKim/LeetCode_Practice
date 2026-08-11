class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        num_set, prefix_len = set(nums), 1

        for prev, curr in zip(nums, nums[1:]):
            if curr == prev + 1:
                prefix_len += 1
            else:
                break

        total = (nums[prefix_len - 1] + nums[0]) * prefix_len >> 1
        while total in num_set:
            total += 1

        return total
        