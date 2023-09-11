class Solution:
    def decodeString(self, s: str) -> str:
        stack, n = [], len(s)
        
        for i in range(n):
            if s[i] == ']':
                decodedString = ""
                
                # get the encoded string
                while stack[-1] != '[':
                    decodedString += stack.pop()
                
                # pop [ from stack
                stack.pop()
                num, base = 0, 1
                while stack and stack[-1].isdigit():
                    num += int(stack.pop()) * base
                    base *= 10
                
                # decode k[decodedString] by pushing decodedStrring k time into stack
                while num > 0:
                    for j in range(len(decodedString) - 1, -1, -1):
                        stack.append(decodedString[j])
                    num -= 1
            
            # push the current character to stack
            else:
                stack.append(s[i])
        
        # get the result from stack
        ans = ""
        for i in range(len(stack) - 1, -1, -1):
            ans = stack.pop() + ans
        
        return ans