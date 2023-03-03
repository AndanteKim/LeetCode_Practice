class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m, n = len(needle), len(haystack)
        
        if n < m: return -1
        
        longest_border = [0] * m
        
        prev = 0
        i = 1
        
        while i < m:
            if needle[i] == needle[prev]:
                prev += 1
                longest_border[i] = prev
                i += 1
            else:
                if prev == 0:
                    longest_border[i] = 0
                    i += 1
                else:
                    prev = longest_border[prev - 1]
                    
        haystack_pointer, needle_pointer = 0, 0
        
        while haystack_pointer < n:
            if haystack[haystack_pointer] == needle[needle_pointer]:
                needle_pointer += 1
                haystack_pointer += 1
                if needle_pointer == m:
                    return haystack_pointer - m
            else:
                if needle_pointer == 0:
                    haystack_pointer += 1
                else:
                    needle_pointer = longest_border[needle_pointer - 1]
        return -1