class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        # Pointer to place non-zero elements
        n, write_idx = len(nums), 0

        for idx in range(n):
            # Step 1: Merge adjacent equal elements if they are non-zero
            if (
                idx < n - 1
                and nums[idx] == nums[idx + 1]
                and nums[idx] != 0
            ):
                nums[idx] *= 2
                nums[idx + 1] = 0

            # Step 2: Shift non-zero elements to the front
            if nums[idx] != 0:
                if idx != write_idx:
                    nums[idx], nums[write_idx] = nums[write_idx], nums[idx]

                write_idx += 1

        return nums

        