class Solution:
    def minimumLength(self, s: str) -> int:
        n = len(s)
        i, j = 0, n - 1
        
        while i < j:
            prefix, suffix = s[i], s[j]
            
            if prefix == suffix:
                while i <= j and prefix == s[i]:
                    i += 1
                
                while i <= j and suffix == s[j]:
                    j -= 1
            else:
                break
            
        return j - i + 1