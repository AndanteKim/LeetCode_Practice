class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        groups = defaultdict(list)
        
        for i, num in enumerate(nums):
            groups[num].append(i)
        
        ans = float('inf')
        for _, group in groups.items():
            if len(group) < 2:
                continue

            for i in range(0, len(group) - 2):
                curr = abs(group[i] - group[i + 1]) + abs(group[i + 1] - group[i + 2]) + abs(group[i + 2] - group[i])
                ans = min(ans, curr)
                
        return -1 if ans == float('inf') else ans