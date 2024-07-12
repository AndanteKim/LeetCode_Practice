class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        ans, s = 0, list(s)
        
        if x > y:
            # Remove "ab" first (higher points), then "ba"
            ans += self.remove_substr(s, "ab", x)
            ans += self.remove_substr(s, "ba", y)
        else:
            # Remove "ba" first (higher, or equal points), then "ab"
            ans += self.remove_substr(s, "ba", y)
            ans += self.remove_substr(s, "ab", x)
        
        return ans
    
    def remove_substr(self, input: str, target: str, points_per_removal: int) -> str:
        total, write_idx = 0, 0
        
        # Iterate through the string
        for read_idx in range(len(input)):
            # Add the current character"
            input[write_idx] = input[read_idx]
            write_idx += 1
            
            # Check if we've written at least 2 characters and
            # they match the target substring
            if (write_idx > 1 and input[write_idx - 2] == target[0] and\
                input[write_idx - 1] == target[1]):
                write_idx -= 2
                total += points_per_removal
                
        # Trim the list to remove any leftover characters
        del input[write_idx:]
        
        return total