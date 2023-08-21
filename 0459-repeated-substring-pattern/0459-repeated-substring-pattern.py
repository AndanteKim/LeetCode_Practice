class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for chunk_size in range(1, n // 2 + 1):
            if n % chunk_size == 0:
                can_split = True
                for i in range(chunk_size, n):
                    if s[i - chunk_size] != s[i]:
                        can_split = False
                        break
                
                if can_split:
                    return True
        return False