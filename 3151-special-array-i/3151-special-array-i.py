class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        # Iterate  through indics 0 to n - 1
        for i in range(len(nums) - 1):
            # Compare the parities of the current and next number
            if nums[i] % 2 == nums[i + 1] % 2:
                # If the two adjacent numbers have the same parity, return False
                return False

        # Return True if no pair of adjacent numbers with the same parity are found
        return True