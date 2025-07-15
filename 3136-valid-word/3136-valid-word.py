class Solution:
    def isValid(self, word: str) -> bool:
        
        if len(word) < 3:
            return False

        chars, vowel_exist, consonant_exist = set(word), False, False
        vowels_list = ('A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u')

        for c in chars:
            order = ord(c)
            # If the character is not digits or a English letter
            if not (ord('0') <= order <= ord('9') or 65 <= order <= 90 or 97 <= order <= 122):
                return False
            
            if c in vowels_list:
                vowel_exist = True
            
            if (65 <= order <= 90 or 97 <= order <= 122) and c not in vowels_list:
                consonant_exist = True
        
        return vowel_exist and consonant_exist