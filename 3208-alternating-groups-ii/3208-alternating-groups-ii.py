class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        ans, n, prev = 0, len(colors), -1
        left = 0

        for right in range(0, n + k - 1):
            while prev == colors[right % n] and left < right:
                left += 1

            prev = colors[right % n]
            if right - left + 1 >= k:
                ans += 1

        return ans
