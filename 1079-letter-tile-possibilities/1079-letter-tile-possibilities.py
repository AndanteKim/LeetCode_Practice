class Solution:
    def _find_sequences(self, char_cnt: Dict[chr, int]) -> int:
        ans = 0

        # Try using each available character
        for c in char_cnt:
            if char_cnt[c] == 0:
                continue
            
            # Add current character and recurse
            ans += 1
            char_cnt[c] -= 1
            ans += self._find_sequences(char_cnt)
            char_cnt[c] += 1

        return ans

    def numTilePossibilities(self, tiles: str) -> int:
        # Track frequency of each uppercase letter (A-Z)
        char_cnt = dict()
        for c in tiles:
            char_cnt[c] = char_cnt.get(c, 0) + 1
        
        # Find all possible sequences using character frequencies
        return self._find_sequences(char_cnt)