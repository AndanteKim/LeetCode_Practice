class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        lookup = defaultdict(int)
        for num in nums:
            lookup[num] += 1
        ans_candidates = []
        for key, val in lookup.items():
            if val == 1:
                ans_candidates.append(key)
        return max(ans_candidates) if ans_candidates else -1