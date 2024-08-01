class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        start, end = 1, len(s) - 1
        
        while start <= end:
            mid = (start + end) >> 1
            
            # Check if there's a repeating substring of length mid
            if self._has_repeating_substr(s, mid):
                start = mid + 1     # Try longer substrings
            else:
                end = mid - 1       # Try shorter substrings
                
        return start - 1
    
    def _has_repeating_substr(self, s: str, length: int) -> bool:
        seen = set()
        for i in range(len(s) - length + 1):
            # Extract a substring of the given length
            substr = s[i : i + length]
            
            # Check if the substring has been seen before
            if substr in seen:
                return True
            seen.add(substr)
            
        return False
            