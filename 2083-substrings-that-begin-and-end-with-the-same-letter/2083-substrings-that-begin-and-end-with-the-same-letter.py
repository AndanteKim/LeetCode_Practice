class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        ans, freq_count = 0, [0] * 26
        
        # Count the frequency of each character in the string.
        for ch in s:
            freq_count[ord(ch) - 97] += 1
            
        # Calculate the total number of valid substrings
        for curr_count in freq_count:
            # Using (curr_count + 1) choose 2 to calculate valid substrings
            # for the current letter.
            ans += ((curr_count + 1) * curr_count) >> 1
        
        return ans