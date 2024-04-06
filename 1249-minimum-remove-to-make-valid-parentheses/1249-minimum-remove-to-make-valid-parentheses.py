class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        indices_to_remove = set()
        stack = []
        for i in range(len(s)):
            if s[i] not in "()":
                continue
                
            if s[i] == '(':
                stack.append(i)
            elif not stack:
                indices_to_remove.add(i)
            else:
                stack.pop()
        
        while stack:
            indices_to_remove.add(stack.pop())
        
        string_builder = []
        for i in range(len(s)):
            if i not in indices_to_remove:
                string_builder.append(s[i])
        
        return "".join(string_builder)