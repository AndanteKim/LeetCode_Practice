class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split()
        
        return len(s) == len(pattern) and len(set(s)) == len(set(pattern)) == len(set(zip(s, pattern)))