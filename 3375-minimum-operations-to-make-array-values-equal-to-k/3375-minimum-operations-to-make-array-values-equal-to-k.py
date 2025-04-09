class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans, seen = 0, set()

        for num in nums:
            if num in seen:
                continue
            
            if num < k:
                return -1
            elif num > k:
                ans += 1
            seen.add(num)

        return ans