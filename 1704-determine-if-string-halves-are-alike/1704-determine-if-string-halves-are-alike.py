class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n, vowels = len(s), {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        a, b = s[:n // 2], s[n//2:]
        cnt_a, cnt_b = 0, 0
        
        for i in range(len(a)):
            if a[i] in vowels:
                cnt_a += 1
        
        for i in range(len(b)):
            if b[i] in vowels:
                cnt_b += 1
                
        return cnt_a == cnt_b
        
        