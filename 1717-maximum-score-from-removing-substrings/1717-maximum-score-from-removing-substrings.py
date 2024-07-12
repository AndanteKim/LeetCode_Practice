class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        ans = 0
        high_priority = "ab" if x > y else "ba"
        low_priority = "ba" if high_priority == "ab" else "ab"
        
        # First pass: remove high priority pair
        str_after_first_pass = self.remove_substr(s, high_priority)
        removed_pairs_count = (len(s) - len(str_after_first_pass)) >> 1
        
        # Calculate score from the first pass
        ans += removed_pairs_count * max(x, y)
        
        # Second pass: remove low priority pair
        str_after_second_pass = self.remove_substr(str_after_first_pass, low_priority)
        removed_pairs_count = (len(str_after_first_pass) - len(str_after_second_pass)) >> 1
        
        # Caculate score from second pass
        ans += removed_pairs_count * min(x, y)
        
        return ans
    
    def remove_substr(self, input: str, target: str) -> str:
        stack = []
        
        # Iterate through each character in the input string
        for c in input:
            # Check if current character forms the target pair with the top of the stack
            if (c == target[1] and stack and stack[-1] == target[0]):
                stack.pop() # Remove the matching character from the stack
            else:
                stack.append(c)
                
        # Reconstruct the remaining string after removing target pairs
        return "".join(stack)
        