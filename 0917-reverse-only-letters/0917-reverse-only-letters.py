class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        left, right = 0, len(s) - 1
        reverse_s = [c for c in s]
        
        while left < right:
            if (s[left].isalpha() and s[right].isalpha()):
                reverse_s[left], reverse_s[right] = reverse_s[right], reverse_s[left]
                left += 1
                right -= 1
            elif not s[left].isalpha():
                left += 1
            elif not s[right].isalpha():
                right -= 1
            
        return "".join(reverse_s)