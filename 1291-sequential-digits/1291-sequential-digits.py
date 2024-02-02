class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        def backtrack(curr: int, start: int, digit: int) -> None:
            if digit == 0:
                curr += start
                if low <= curr <= high:
                    ans.append(curr)
                return
            
            backtrack(curr + (start * (10 ** digit)), start + 1, digit - 1)
            
        ans, low_digit, high_digit = [], 0, 0
        lowest, highest = low, high
        
        while lowest >= 10:
            lowest //= 10
            low_digit += 1
            
            
        while highest >= 10:
            highest //= 10
            high_digit += 1
            
        for digit in range(low_digit, high_digit + 1):
            for i in range(1, 10 - digit):
                curr = i * (10 ** digit)
                backtrack(curr, i + 1, digit - 1)
        
        return ans