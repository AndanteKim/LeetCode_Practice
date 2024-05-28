class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        def is_match(s_i: int, p_i: int) -> bool:
            # Base case: reached end of pattern
            if p_i == len_p:
                return s_i == len_s # True iff also reached end of s
            
            # Get current pattern character
            symbol = pattern[p_i]
            
            # This symbol already has an associated word
            if symbol in symbol_map:
                word = symbol_map[symbol]
                # Check if we can use it to match s[s_i ... s_i + word.length()]
                if s[s_i : s_i + len(word)] != word:
                    return False
                
                # If it matches continue to maatch the rest
                return is_match(s_i + len(word), p_i + 1)
            
            # This symbol does not exist in the map
            for k in range(s_i + 1, len_s + 1):
                new_word = s[s_i : k]
                if new_word in word_set:
                    continue
                    
                # Create or update it
                symbol_map[symbol] = new_word
                word_set.add(new_word)
                
                # Continue to match the rest
                if is_match(s_i + len(new_word), p_i + 1):
                    return True
                
                # Backtracking
                del symbol_map[symbol]
                word_set.remove(new_word)
            
            return False
        
        len_p, len_s = len(pattern), len(s)
        symbol_map, word_set = dict(), set()
        return is_match(0, 0)