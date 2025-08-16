class Solution:
    def maximum69Number (self, num: int) -> int:
        digits, n = [], num

        while n > 0:
            digits.append(n % 10)
            n //= 10

        digits.reverse()
        digit, changeable = len(digits) - 1, True
        ans = 0

        for d in digits:
            if changeable and d == 6:
                ans += 9 * (10 ** digit)
                changeable = False
            else:
                ans += d * (10 ** digit)
            digit -= 1
        
        return ans