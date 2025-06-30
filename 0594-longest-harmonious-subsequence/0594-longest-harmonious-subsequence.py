class Solution:
    def findLHS(self, nums: List[int]) -> int:
        ans, freq = 0, dict()

        for num in nums:
            freq[num] = freq.get(num, 0) + 1

            if num + 1 in freq:
                ans = max(ans, freq[num] + freq[num + 1])
            
            if num - 1 in freq:
                ans = max(ans, freq[num] + freq[num - 1])

        return ans