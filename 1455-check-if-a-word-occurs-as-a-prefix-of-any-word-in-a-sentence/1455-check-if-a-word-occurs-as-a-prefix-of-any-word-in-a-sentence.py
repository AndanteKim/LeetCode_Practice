class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words, n = sentence.split(), len(searchWord)
        for i, word in enumerate(words):
            j, m, is_prefix = 0, len(word), True
            
            if m < n:
                continue
            
            while j < n:
                if word[j] != searchWord[j]:
                    is_prefix = False
                    break
                j += 1
            
            if is_prefix:
                return i + 1
        
        return -1