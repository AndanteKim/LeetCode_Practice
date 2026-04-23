class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        n, groups = len(nums), defaultdict(list)
        ans = [0] * n

        for i, num in enumerate(nums):
            groups[num].append(i)
        
        for group in groups.values():
            total = sum(group)
            prefix, sz = 0, len(group)
                
            for i, idx in enumerate(group):
                ans[idx] = total - prefix * 2 + idx * (2 * i - sz)
                prefix += idx

        return ans