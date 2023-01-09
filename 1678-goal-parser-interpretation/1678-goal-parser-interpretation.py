class Solution:
    def interpret(self, command: str) -> str:
        ans, i = "", 0
        while i < len(command):
            if command[i].isalpha():
                ans += command[i]
                i += 1
                continue
            if command[i] == '(' and command[i+1] == ')':
                ans += 'o'
                i += 2
            else:
                i += 1
        return ans
            