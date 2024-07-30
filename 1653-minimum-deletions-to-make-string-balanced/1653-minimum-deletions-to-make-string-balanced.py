class Solution:
    def minimumDeletions(self, s: str) -> int:
        n, stack, delete_count = len(s), [], 0
        
        # Iterate through each character in the string
        for i in range(n):
            # If the stack is not empty, top of stack is 'b',
            # and current char is 'a'
            if stack and s[stack[-1]] == 'b' and s[i] == 'a':
                stack.pop()     # Remove 'b' from stack
                delete_count += 1   # Increment deletion count
            else:
                stack.append(i)     # Append current character to stack
        
        return delete_count