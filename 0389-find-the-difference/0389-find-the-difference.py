class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        
        return "".join(c for c in Counter(t) - Counter(s))