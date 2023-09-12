class Solution:
    def minDeletions(self, s: str) -> int:
        
        # store the frequency of each character
        frequencies = [0] * 26
        for c in s:
            frequencies[ord(c) - 97] += 1
        
        frequencies.sort(reverse = True)
        ans = 0
        # max frequency the current character can have
        max_freq_allowed = len(s)
        
        # Iterate over the frequencies in descending order
        for freq in frequencies:
            # Delete characters to make the frequency equal the maximum frequency allowed
            if freq > max_freq_allowed:
                ans += freq - max_freq_allowed
                freq = max_freq_allowed
            
            # Update the maximum allowed frequency
            max_freq_allowed = max(0, freq - 1)
        
        return ans