class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        first_idx_diff, second_idx_diff = 0, 0
        num_diffs = 0

        for i in range(len(s1)):
            if s1[i] != s2[i]:
                num_diffs += 1
                # num_diffs is more than 2, one string swap won't make two strings equal
                if num_diffs > 2:
                    return False
                elif num_diffs == 1:
                    # Store the index of first difference
                    first_idx_diff = i
                else:
                    # Store the index of second difference
                    second_idx_diff = i

        # Check if swap is possible
        return s1[first_idx_diff] == s2[second_idx_diff] and s1[second_idx_diff] == s2[first_idx_diff]

