class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        # Create an original array initialized with 0.
        original, n = [0], len(derived)
        for i in range(n):
            original.append(derived[i] ^ original[i])

        # Store the validation results in check_for_zero and check_for_one respectively
        check_for_zero = original[0] == original[-1]
        original = [1]
        for i in range(n):
            original.append(derived[i] ^ original[i])
        check_for_one = original[0] == original[-1]

        return check_for_zero or check_for_one
