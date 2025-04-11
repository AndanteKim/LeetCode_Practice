class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        ans = 0
        
        for num in range(low, high + 1):
            curr = str(num)
            n = len(curr)
            if n % 2:
                continue
            
            j = n >> 1
            first, second = 0, 0
            for i in range(n >> 1):
                first += int(curr[i])
                second += int(curr[i + j])
            
            if first == second:
                ans += 1

        return ans