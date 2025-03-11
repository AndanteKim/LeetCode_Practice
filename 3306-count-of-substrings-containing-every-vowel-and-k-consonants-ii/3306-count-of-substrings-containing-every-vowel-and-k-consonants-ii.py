class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        def _is_vowel(ch: chr) -> bool:
            return ch == 'a' or ch == 'e' or ch == 'i'\
            or ch == 'o' or ch == 'u'

        ans, left, n = 0, 0, len(word)
        vowel_cnt = defaultdict(int)  # Dictionary to keep counts of vowels
        consonant_cnt = 0   # Count of consonants
        next_consonant = [0] * n    # Array to compute index of next consonant for all indices
        next_consonant_idx = n

        for i in range(n - 1, -1, -1):
            next_consonant[i] = next_consonant_idx
            if not _is_vowel(word[i]):
                next_consonant_idx = i
        
        for right in range(n):
            new_ch = word[right]
            if _is_vowel(new_ch):
                vowel_cnt[new_ch] += 1
            else:
                consonant_cnt += 1

            while consonant_cnt > k:
                # Shrink window if too many consonants are present
                start_ch = word[left]
                if _is_vowel(start_ch):
                    vowel_cnt[start_ch] -= 1
                    if vowel_cnt[start_ch] == 0:
                        del vowel_cnt[start_ch]
                else:
                    consonant_cnt -= 1
                left += 1
            
            while left < n \
            and len(vowel_cnt) == 5\
            and consonant_cnt == k:
                # Try to shrink if window is valid
                ans += next_consonant[right] - right
                start_ch = word[left]
                if _is_vowel(start_ch):
                    vowel_cnt[start_ch] -= 1
                    if vowel_cnt[start_ch] == 0:
                        del vowel_cnt[start_ch]
                else:
                    consonant_cnt -= 1
                left += 1

        return ans