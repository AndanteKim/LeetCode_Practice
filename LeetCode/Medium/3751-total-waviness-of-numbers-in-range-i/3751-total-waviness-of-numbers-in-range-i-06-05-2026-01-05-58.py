class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        ans = 0

        for num in range(num1, num2 + 1):
            mapping, curr, n = dict(), [], 0

            while num > 0:
                heappush(curr, (num % 10, n))
                mapping[n] = num % 10
                num //= 10
                n += 1

            while curr:
                digit, idx = heappop(curr)
                
                if idx == 0 or idx == n - 1:
                    continue

                if (mapping[idx - 1] > mapping[idx] and mapping[idx] < mapping[idx + 1]) or (mapping[idx] > mapping[idx - 1] and mapping[idx] > mapping[idx + 1]):
                    ans += 1

        return ans