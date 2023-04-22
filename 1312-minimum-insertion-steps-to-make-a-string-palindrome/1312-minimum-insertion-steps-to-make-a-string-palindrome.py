class Solution:
    @cache
    def Insertions(self, left: int, right: int, s: str) -> int:
        if left >= right:
            return 0
        elif s[left] == s[right]:
            return self.Insertions(left + 1, right - 1, s)
        else:
            return 1 + min(self.Insertions(left + 1, right, s), self.Insertions(left, right - 1, s))
    
    def minInsertions(self, s: str) -> int:
        return self.Insertions(0, len(s) - 1, s)