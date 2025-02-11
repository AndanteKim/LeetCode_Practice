class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        stack = []
        n, part_len, start_ptr = len(s), len(part), 0

        # Iterate through each character in the string
        for c in s:
            # Push current character to stack
            stack.append(c)

            # If stack size is greater than or equal to the part length, check for match
            if len(stack) >= part_len and "".join(stack[-part_len:]) == part:
                # Pop the characters matching 'part' from the stack
                for _ in range(part_len):
                    stack.pop()


        # Convert stack to string with correct order
        return "".join(stack)
