class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        seen = set()
        length = len(s) - 1
        
        for max_len in range(length, 0, -1):
            seen.clear()
            
            for start in range(len(s) - max_len + 1):
                end = start
                # Extract substring of length max_length
                curr_substr = s[end : end + max_len]
                
                # If the substring is already in the set,
                # it means we've found a repeating substring
                if curr_substr in seen:
                    return max_len
                
                seen.add(curr_substr)
                
        return 0