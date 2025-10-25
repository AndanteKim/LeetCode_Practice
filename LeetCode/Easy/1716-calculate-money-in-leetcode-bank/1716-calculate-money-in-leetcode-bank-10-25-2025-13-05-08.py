class Solution:
    def totalMoney(self, n: int) -> int:
        ans, start = 0, 1

        for day in range(n // 7):
            for money in range(start, start + 7):
                ans += money
            start += 1

        for money in range(start, start + (n % 7)):
            ans += money

        return ans