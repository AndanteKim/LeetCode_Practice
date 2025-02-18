class Solution:
    def smallestNumber(self, pattern: str) -> str:
        ans, stack = [], []

        # Iterate through the pattern
        for idx in range(len(pattern) + 1):
            # Push the next number onto the stack
            stack.append(idx + 1)

            # If 'I' is encountered or we reach the end, pop all stack elements
            if idx == len(pattern) or pattern[idx] == 'I':
                while stack:
                    ans.append(str(stack.pop()))
        
        return "".join(ans)