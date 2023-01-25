class Solution:
    def repeatedCharacter(self, s: str) -> str:
        lookup = set()
        for c in s:
            if c in lookup:
                return c
            lookup.add(c)
        return ""