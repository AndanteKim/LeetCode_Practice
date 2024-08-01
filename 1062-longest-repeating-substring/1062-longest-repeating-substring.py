class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        start, length = 0, len(s)
        max_len, seen = 0, set()
        
        while start < length:
            end = start
            # Stop if it's not possible to find a
            # longer repeating substring
            if end + max_len >= length:
                return max_len
            
            # Generate substrings of length max_length + 1
            curr_substr = s[end : end + max_len + 1]
            
            # If a repeating substring is found,
            # increase max_len and restart
            if curr_substr in seen:
                start = -1  # Restart search for new length
                seen.clear()
                max_len += 1
                
            else:
                seen.add(curr_substr)
                
            start += 1
            
        return max_len