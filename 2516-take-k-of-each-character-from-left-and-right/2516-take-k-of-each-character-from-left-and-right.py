class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        count = [0] * 3
        
        # Count total occurrences
        for c in s:
            count[ord(c) - 97] += 1
            
        # Check if we've enough characters    
        for i in range(3):
            if count[i] < k:
                return -1
            
        window, n = [0] * 3, len(s)
        left, max_window = 0, 0
        
        # Find the longest window that leaves k of each character outside
        for right in range(n):
            window[ord(s[right]) - 97] += 1
            
            # Shrink window if we take too many characters
            while left <= right and (count[0] - window[0] < k \
                                     or count[1] - window[1] < k \
                                     or count[2] - window[2] < k):
                window[ord(s[left]) - 97] -= 1
                left += 1
            
            max_window = max(max_window, right - left + 1)
            
        return n - max_window