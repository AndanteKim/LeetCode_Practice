class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            i, j, is_pal = 0, len(word) - 1, True
            
            while i <= j:
                if word[i] != word[j]:
                    is_pal = False
                    break
                i += 1
                j -= 1
            
            if is_pal:
                return word
        return ""