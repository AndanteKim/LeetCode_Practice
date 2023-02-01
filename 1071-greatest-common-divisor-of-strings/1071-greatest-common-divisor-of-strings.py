class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)
        
        prefix_candidates = list()
        for i in range(1, n+1):
            prefix = str2[:i]
            if prefix * (m // i) == str1 and prefix * (n // i) == str2:
                prefix_candidates.append(prefix)
        
        return prefix_candidates[-1] if prefix_candidates else ""
        