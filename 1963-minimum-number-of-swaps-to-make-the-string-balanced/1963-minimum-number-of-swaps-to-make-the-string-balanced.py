class Solution:
    def minSwaps(self, s: str) -> int:
        stack_size, unbalanced = 0, 0
        
        for c in s:
            # If the character is opening bracket, increment the stack size.
            if c == '[':
                stack_size += 1
            else:
                # If the character is closing bracket, and we have an opening bracket, decrease
                # the stack size.
                if stack_size > 0:
                    stack_size -= 1
                    
        return (stack_size + 1) >> 1