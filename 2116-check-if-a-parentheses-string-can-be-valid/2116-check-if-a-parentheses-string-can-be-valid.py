class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        # Base case
        if len(s) == 0 or len(s) % 2:
            return False

        open_brackets, unlocked = [], []

        # Iterate through the string to handle '(' and ')'
        for i, c in enumerate(s):
            if locked[i] == '0':
                unlocked.append(i)
            elif c == '(':
                open_brackets.append(i)
            else:
                if open_brackets:
                    open_brackets.pop()
                elif unlocked:
                    unlocked.pop()
                else:
                    return False
        
        # Match remaining open brackets and the unlocked characters
        while open_brackets and unlocked and open_brackets[-1] < unlocked[-1]:
            open_brackets.pop()
            unlocked.pop()

        return False if open_brackets else True