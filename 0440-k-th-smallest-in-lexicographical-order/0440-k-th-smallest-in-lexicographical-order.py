class Solution:
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
            
            if steps <= k:
                curr += 1
                k -= steps
            else:
                curr *= 10
                k -= 1
                
        return curr
            