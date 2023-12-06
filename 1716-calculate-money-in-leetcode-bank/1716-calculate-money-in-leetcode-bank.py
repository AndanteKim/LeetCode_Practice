class Solution:
    def totalMoney(self, n: int) -> int:
        i, ans, start, end = 0, 0, 1, 7
        while i < n:
            if i + 7 < n:
                ans += 7 * (start + end) // 2
            else:
                ans += (n - i) * (2 * start + (n - i - 1)) // 2
                break
            i += 7
            start += 1
            end += 1
        return ans
        