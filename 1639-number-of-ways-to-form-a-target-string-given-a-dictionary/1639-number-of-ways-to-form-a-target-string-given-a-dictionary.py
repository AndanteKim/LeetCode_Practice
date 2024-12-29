class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        word_length, target_length = len(words[0]), len(target)
        char_freq, mod = [[0] * 26 for _ in range(word_length)], 1_000_000_007

        # Step 1: Calculate the frequency of each charactersat every index in "words".
        for word in words:
            for j in range(word_length):
                char_freq[j][ord(word[j]) - 97] += 1

        # Step 2: Initialize two DP arrays: prev_dp and dp
        prev_dp, dp = [0] * (target_length + 1), [0] * (target_length + 1)

        # Base case: There is one way to form an empty target string
        prev_dp[0], dp[0] = 1, 1

        # Step 3: Fill the dp table
        for curr_word in range(1, word_length + 1):
            # Carry over the previous one (not using this index of "words").
            dp = prev_dp[:]
            for curr_target in range(1, target_length + 1):
                # Add ways using the current index of "words" if the characters match
                curr_pos = ord(target[curr_target - 1]) - 97
                dp[curr_target] += char_freq[curr_word - 1][curr_pos] * prev_dp[curr_target - 1]
                dp[curr_target] %= mod

            # Move current row to previous row for the next iteration.
            prev_dp = dp[:]

        # Step 4: The result is in prev_dp[target_length]
        return prev_dp[target_length]

        
