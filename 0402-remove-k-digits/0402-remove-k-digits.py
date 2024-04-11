class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        ans, stack = "", []
        
        # Construct a monotone increasing sequence of digits 
        for digit in num:
            while k > 0 and stack and digit < stack[-1]:
                stack.pop()
                k -= 1
                
            stack.append(digit)
        
        # Trunk the remaining k digits at the end
        # in the case k == 0: return the entire list
        final_stack = stack[:-k] if k else stack
        
        # Trip the leading zeros
        return "".join(final_stack).lstrip('0') or "0"