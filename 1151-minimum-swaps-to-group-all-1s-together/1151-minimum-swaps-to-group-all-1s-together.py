class Solution:
    def minSwaps(self, data: List[int]) -> int:
        k, n, left = data.count(1), len(data), 0
        ans, swap_count = float('inf'), 0

        for right in range(n):
            if data[right] == 0:
                swap_count += 1
            
            while right - left >= k:
                if data[left] == 0:
                    swap_count -= 1
                left += 1 
            
            if right + 1 >= k:
                ans = min(ans, swap_count)
        
        return ans