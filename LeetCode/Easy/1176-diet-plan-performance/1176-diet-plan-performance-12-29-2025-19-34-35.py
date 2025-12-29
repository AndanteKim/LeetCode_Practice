class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        n, T, left = len(calories), sum(calories[:k]), 0
        ans = 1 if T > upper else -1 if T < lower else 0
        for right in range(k, n):
            T -= calories[left]
            left += 1
            T += calories[right]
            ans += (1 if T > upper else -1 if T < lower else 0)

        return ans