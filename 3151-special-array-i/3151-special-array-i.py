class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        # Iterate through indices 0 to n - 1
        for i in range(len(nums) - 1):
            # Compare the parities using bitwise operations
            if ((nums[i] & 1) ^ (nums[i + 1] & 1)) == 0:
                # If the two adjacent numbers have the same parity, return False
                return False

        # Return True if no pair of adjacent numbers with the same parity are found
        return True