class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        indices = defaultdict(list)

        for i, num in enumerate(nums):
            indices[num].append(i)

        ans = float('inf')
        for _, elems in indices.items():
            if len(elems) <= 2:
                continue
            
            for i in range(len(elems) - 2):
                curr = abs(elems[i] - elems[i + 1]) + abs(elems[i + 1] - elems[i + 2]) + abs(elems[i + 2] - elems[i])
                ans = min(ans, curr)

        return -1 if ans == float('inf') else ans