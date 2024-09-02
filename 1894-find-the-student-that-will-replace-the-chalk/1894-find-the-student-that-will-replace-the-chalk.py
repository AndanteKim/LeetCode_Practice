class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        # Find the sum of all elements.
        sum = 0
        
        for i in range(len(chalk)):
            sum += chalk[i]
            if sum > k:
                break
                
        # Find modulo of k with sum
        k %= sum
        
        for i in range(len(chalk)):
            if k < chalk[i]:
                return i
            k -= chalk[i]
            
        return 0