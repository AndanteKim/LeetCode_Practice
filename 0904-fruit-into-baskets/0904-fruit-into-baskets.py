class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        left, n = 0, len(fruits)
        ans, seen = 0, defaultdict(int)

        for right in range(n):
            while fruits[right] not in seen and len(seen) >= 2:
                seen[fruits[left]] -= 1
                if seen[fruits[left]] == 0:
                    del seen[fruits[left]]
                left += 1
            
            seen[fruits[right]] += 1
            ans = max(ans, right - left + 1)

        return ans