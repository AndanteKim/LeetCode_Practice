class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2): return False
        word1Map, word2Map = [0] * 26, [0] * 26
        
        word1Bit, word2Bit = 0, 0
        for c in word1:
            word1Map[ord(c) - ord('a')] += 1
            word1Bit = word1Bit | (1 << ord(c) - ord('a'))
        
        for c in word2:
            word2Map[ord(c) - ord('a')] += 1
            word2Bit = word2Bit | (1 << ord(c) - ord('a'))
        
        if word1Bit != word2Bit: return False
        
        word1Map.sort()
        word2Map.sort()
        
        for i in range(26):
            if word1Map[i] != word2Map[i]: return False
        
        return True