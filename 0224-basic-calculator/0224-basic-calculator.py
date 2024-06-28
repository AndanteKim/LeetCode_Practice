class Solution:
    def calculate(self, s: str) -> int:
        st, i, n = [], 0, len(s)
        total, sign = 0, 1
        
        while i < n:
            if s[i].isdigit():
                num = 0
                while i < n and s[i].isdigit():
                    num = num * 10 + ord(s[i]) - ord('0')
                    i += 1
                    
                # As for loop also increase i, so if we don't decrease i here
                # a sign will be skipped
                total += num * sign
                sign = 1
                
            elif s[i] == '(':
                # saving current state of (total, sign) in stack
                st.append((total, sign))
                
                # Resetting sum and sign for inner bracket calculation
                total, sign = 0, 1
                i += 1
                
            elif s[i] == ')':
                total = st[-1][0] + total * st[-1][1]
                st.pop()
                i += 1
            elif s[i] == '-':
                sign *= -1
                i += 1
            else:
                i += 1
                
        return total