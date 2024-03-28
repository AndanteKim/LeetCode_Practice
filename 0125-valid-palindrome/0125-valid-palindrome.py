class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        
        while i < j:
            while i < j and not (48 <= ord(s[i]) < 58 or 65 <= ord(s[i]) < 91 or 97 <= ord(s[i]) < 123):
                i += 1
            while i < j and not (48 <= ord(s[j]) < 58 or 65 <= ord(s[j]) < 91 or 97 <= ord(s[j]) < 123):
                j -= 1
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
            
        return True