class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        stack = s.split()
        
        return len(stack[-1])