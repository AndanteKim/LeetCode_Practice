class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans, curr = [], 1
        
        # Generate numbers from 1 to n
        for _ in range(n):
            ans.append(curr)
            
            # If multiplying the current number by 10 is within the limit, do it.
            if curr * 10 <= n:
                curr *= 10
            else:
                # Adjust the current number by moving up one digit
                while curr % 10 == 9 or curr >= n:
                    curr //= 10     # Remove the last digit
                curr += 1   # Increment the number
                
        return ans