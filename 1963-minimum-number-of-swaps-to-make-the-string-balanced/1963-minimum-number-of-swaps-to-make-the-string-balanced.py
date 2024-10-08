class Solution:
    def minSwaps(self, s: str) -> int:
        stack, unbalanced = [], 0
        
        for c in s:
            # If an opening bracket is encountered, push it in the stack.
            if c == '[':
                stack.append(c)
            else:
                # If the deque isn't empty, pop it.
                if stack:
                    stack.pop()
                
                # Otherwise increase the count of unbalanced brackets
                else:
                    unbalanced += 1
        
        return (unbalanced + 1) >> 1
            