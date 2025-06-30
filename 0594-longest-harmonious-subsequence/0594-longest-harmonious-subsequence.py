class Solution:
    def findLHS(self, nums: List[int]) -> int:
        freq = Counter(nums)

        if len(freq) <= 1:
            return 0

        ans = 0
        for num, cnt in freq.items():
            if num - 1 in freq:
                ans = max(ans, cnt + freq[num - 1])
            if num + 1 in freq:
                ans = max(ans, cnt + freq[num + 1])

        return ans