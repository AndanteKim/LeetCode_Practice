class Solution:
    def removeVowels(self, s: str) -> str:
        stack = []
        
        for c in s:
            if c in 'aeiou':
                continue
                
            stack.append(c)
        
        return "".join(stack)