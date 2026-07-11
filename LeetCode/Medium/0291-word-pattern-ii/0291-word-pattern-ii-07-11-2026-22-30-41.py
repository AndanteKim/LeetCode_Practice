class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        def is_match(p_i: int, s_i: int) -> bool:
            # Base case
            if p_i == len(pattern):
                return s_i == len(s)

            symbol = pattern[p_i]
            
            if symbol in mapping:
                word = mapping[symbol]

                if s[s_i : s_i + len(word)] != word:
                    return False
                
                return is_match(p_i + 1, s_i + len(word))

            for k in range(s_i + 1, len(s) + 1):
                new_word = s[s_i : k]
                if new_word in word_set:
                    continue
                mapping[symbol] = new_word
                word_set.add(new_word)

                if is_match(p_i + 1, s_i + len(new_word)):
                    return True
                
                del mapping[symbol]
                word_set.remove(new_word)
            
            return False

        mapping, word_set = dict(), set()
        return is_match(0, 0)
