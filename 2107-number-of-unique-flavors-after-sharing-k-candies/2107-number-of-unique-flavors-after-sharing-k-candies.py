class Solution:
    def shareCandies(self, candies: List[int], k: int) -> int:
        total_flavors, lost_flavors = 0, 0
        count_flavors, n = dict(), len(candies)
        
        for i in range(n):
            if candies[i] not in count_flavors:
                total_flavors += 1
            count_flavors[candies[i]] = count_flavors.get(candies[i], 0) + 1
            
        ans, left = 0, 0
        for right in range(n):
            while right - left >= k:
                if count_flavors[candies[left]] == 0:
                    lost_flavors -= 1
                count_flavors[candies[left]] += 1
                left += 1
            count_flavors[candies[right]] -= 1
            if count_flavors[candies[right]] == 0:
                lost_flavors += 1
                          
            if right >= max(k - 1, 0):
                ans = max(ans, total_flavors - lost_flavors)
                
        return ans