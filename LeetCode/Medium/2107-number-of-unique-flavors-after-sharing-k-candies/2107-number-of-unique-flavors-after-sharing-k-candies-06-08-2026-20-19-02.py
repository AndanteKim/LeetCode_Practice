class Solution:
    def shareCandies(self, candies: List[int], k: int) -> int:
        left = 0
        ans, total_count = 0, Counter(candies)

        # Base case
        if k == 0:
            return len(total_count)

        if len(candies) == k:
            return 0

        for right in range(len(candies)):
            while right - left >= k:
                total_count[candies[left]] += 1
                left += 1
            
            total_count[candies[right]] -= 1
            if total_count[candies[right]] == 0:
                del total_count[candies[right]]
            
            if right - left == k - 1:
                ans = max(ans, len(total_count))
        
        return ans