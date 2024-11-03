class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        def compute_lps(pattern: str) -> List[int]:
            pattern_len = len(pattern)
            lps = [0] * pattern_len
            length, idx = 0, 1
            
            # Build the LPS array
            while idx < pattern_len:
                # If characters match, increment length and set lps value
                if pattern[idx] == pattern[length]:
                    length += 1
                    lps[idx] = length
                    idx += 1
                # If there's a mismatch, update length using the previous LPS value
                elif length > 0:
                    length = lps[length - 1]
                # No match and length is zero
                else:
                    lps[idx] = 0
                    idx += 1
            return lps
        
        def kmp_search(pattern: str, text: str) -> bool:
            # Precompute the LPS(Longest Prefix Suffix) array for the pattern
            lps = compute_lps(pattern)
            text_idx = pattern_idx = 0
            text_len, pattern_len = len(text), len(pattern)
            
            # Loop through the text to find the pattern
            while text_idx < text_len:
                # If characters match, move both indices forward
                if text[text_idx] == pattern[pattern_idx]:
                    text_idx += 1
                    pattern_idx += 1
                    
                    # If we've matched the entire pattern, return true
                    if pattern_idx == pattern_len:
                        return True
                # If there's a mismatch after some matches, use the LPS array to skip unnecessary comparisons
                elif pattern_idx > 0:
                    pattern_idx = lps[pattern_idx - 1]
                # If no matches, move to the next character in text.
                else:
                    text_idx += 1
            # Pattern not found in text
            return False
        
        # Base case
        if len(s) != len(goal):
            return False
        
        double_str = s + s
        
        return kmp_search(goal, double_str)