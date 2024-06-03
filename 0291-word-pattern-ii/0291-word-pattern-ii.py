class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        def is_match(s_i: int, p_i: int) -> bool:
            # Base case: reached end of pattern
            if p_i == len(pattern):
                return s_i == len(s) # True iff also reached end of s
            
            # Get current pattern character
            symbol = pattern[p_i]
            
            # This symbol already has an associated wrod
            if symbols[ord(symbol) - 97]:
                word = symbols[ord(symbol) - ord("a")]
                
                # Check if it matches s[s_index ... s_index + len(word)]
                if s[s_i : s_i + len(word)] != word:
                    return False
                
                # If it matches, continue to match the rest
                return is_match(s_i + len(word), p_i + 1)
            
            # Count the number of spots the remaining symbols in the pattern take
            filled_spots = 0
            for i in range(p_i + 1, len(pattern)):
                if symbols[ord(pattern[i]) - 97]:
                    filled_spots += len(symbols[ord(pattern[i]) - 97])
                else:
                    filled_spots += 1
                    
            # This symbol doesn't have an associated word
            for k in range(s_i + 1, len(s) - filled_spots + 1):
                new_word = s[s_i:k]
                if new_word in word_set:
                    continue
                
                # Create or update it
                symbols[ord(symbol) - 97] = new_word
                word_set.add(new_word)
                
                # Continue to match the rest
                if is_match(k, p_i + 1):
                    return True
                
                # Backtracking
                symbols[ord(symbol) - 97] = ""
                word_set.remove(new_word)
                
            # No mappings were valid
            return False
        
        symbols, word_set = [""] * 26, set()
        
        return is_match(0, 0)