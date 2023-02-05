class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        chars_word1 = [0] * 26
        chars_word2 = [0] * 26
        
        for c in word1:
            chars_word1[ord(c) - ord('a')] += 1
        for c in word2:
            chars_word2[ord(c) - ord('a')] += 1
        
        for i in range(26):
            if (chars_word1[i] > 0 and chars_word2[i] == 0) or (chars_word1[i] == 0 and chars_word2[i] > 0):
                return False
        
        chars_word1.sort()
        chars_word2.sort()
        return chars_word1 == chars_word2