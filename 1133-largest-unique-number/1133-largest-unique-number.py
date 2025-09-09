class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        freq = dict()
        for num in nums:
            freq[num] = freq.get(num, 0) + 1

        ans = -1

        for num, cnt in freq.items():
            if cnt == 1:
                ans = max(ans, num)

        return ans