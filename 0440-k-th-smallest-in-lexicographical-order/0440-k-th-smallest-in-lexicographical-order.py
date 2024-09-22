class Solution:
    # To count how many numbers exist between prefix1 and prefix2
    def count_steps(self, n: int, prefix1: int, prefix2: int) -> int:
        steps = 0
        
        while prefix1 <= n:
            steps += min(n + 1, prefix2) - prefix1
            prefix1 *= 10
            prefix2 *= 10
            
        return steps
    
    def findKthNumber(self, n: int, k: int) -> int:
        curr = 1
        k -= 1
        
        while k > 0:
            steps = self.count_steps(n, curr, curr + 1)
            
            # If the steps are less than or equal to k, we skip this prefix's subtree
            if steps <= k:
                # Move to the next prefix and decrease k by the number of steps we skip
                curr += 1
                k -= steps
            else:
                # Move to the next level of the tree and decrement k by 1
                curr *= 10
                k -= 1
                
        return curr
            