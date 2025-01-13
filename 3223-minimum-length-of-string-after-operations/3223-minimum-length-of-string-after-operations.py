class Solution:
    def minimumLength(self, s: str) -> int:
        # Step 1: Initialize a frequency array to count occurrences of each character
        total_length, char_freq = 0, [0] * 26

        # Step 2: Count the frequency of each character in the string
        for curr_char in s:
            char_freq[ord(curr_char) - 97] += 1
        
        # Step 3: Calculate the total length after deletions count
        for freq in char_freq:
            if freq == 0:
                continue    # Skip characters that don't appear
            
            if freq % 2:
                total_length += 1   # If frequency is odd, add 1 character
            else:
                total_length += 2   # If frequency is even, add 2 characters

        # Step 4: Return the minimum length after deletions count
        return total_length