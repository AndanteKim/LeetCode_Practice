class Solution:
    def minLength(self, s: str) -> int:
        stack = []
        
        # Iterate over each character in the input string
        for curr_char in s:
            # If the stack is empty, simply push the current character
            if not stack:
                stack.append(curr_char)
                continue
                
            # Check for "AB" pattern, remove the pair by popping from the stack
            if curr_char == 'B' and stack[-1] == 'A':
                stack.pop()
                
            # Check for "CD" pattern, remove the pair by popping from the stack
            elif curr_char == 'D' and stack[-1] == 'C':
                stack.pop()

            # Otherwise, push the current character onto the stack
            else:
                stack.append(curr_char)
                
        return len(stack)
            