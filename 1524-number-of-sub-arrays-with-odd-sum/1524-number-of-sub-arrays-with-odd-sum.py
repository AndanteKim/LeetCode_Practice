class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        MOD = 10 ** 9 + 7
        ans = prefix = 0

        odd_cnt, even_cnt = 0, 1

        for num in arr:
            prefix += num

            if prefix % 2 == 0:
                ans += odd_cnt
                even_cnt += 1
            else:
                ans += even_cnt
                odd_cnt += 1
            ans %= MOD

        return ans