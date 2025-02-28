class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)
        
        # Initialize the first row (when str1 is empty, the supersequence is str2's prefix)
        prev_row = [str2[:col] for col in range(n + 1)]

        # Fill the DP table row by row
        for row in range(1, m + 1):
            # Initialize the first column (when str2 is empty, the supersequence is str1's prefix)
            curr_row = [str1[0:row]] + [None for _ in range(n)]

            for col in range(1, n + 1):
                # If characters match, extend the supersequence from the diagonal value
                if str1[row - 1] == str2[col - 1]:
                    curr_row[col] = prev_row[col - 1] + str1[row - 1]
                else:
                    # If characters don't match, choose the shorter supersequence
                    # From previosu row (exclude current str1 char)
                    pick_s1 = prev_row[col]

                    # From previous column (exclude current str2 char)
                    pick_s2 = curr_row[col - 1]

                    curr_row[col] = (
                        pick_s1 + str1[row - 1]
                        if len(pick_s1) < len(pick_s2)
                        else pick_s2 + str2[col - 1]
                    )

            # Move to the next row (update previous row reference)
            prev_row = curr_row
        
        # Return the shortest common supersequence from the last call
        return prev_row[n]