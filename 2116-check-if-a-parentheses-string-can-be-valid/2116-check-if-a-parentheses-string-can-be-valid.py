class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        n = len(s)
        # Base case: If the length of string is odd, return False
        if n == 0 or n % 2:
            return False

        open_brackets, unlocked = 0, 0

        # Iterate through the string to handle '(' and ')'
        for i, c in enumerate(s):
            if locked[i] == '0':
                unlocked += 1
            elif s[i] == '(':
                open_brackets += 1
            else:
                if open_brackets > 0:
                    open_brackets -= 1
                elif unlocked > 0:
                    unlocked -= 1
                else:
                    return False
        
        # Match remaining open brackets with unlocked characters
        balance = 0
        for i in range(len(s) - 1, -1, -1):
            if locked[i] == '0':
                balance -= 1
                unlocked -= 1
            elif s[i] == '(':
                balance += 1
                open_brackets -= 1
            elif s[i] == ')':
                balance -= 1
            if balance > 0:
                return False
            if unlocked == 0 and open_brackets == 0:
                break
        
        return False if open_brackets > 0 else True