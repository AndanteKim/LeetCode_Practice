class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        counts = defaultdict(int)
        for arr in nums:
            for x in arr:
                counts[x] += 1
        
        n = len(nums)
        ans = []
        for key in counts:
            if counts[key] == n:
                ans.append(key)
        return sorted(ans)