class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key = lambda x: x[1] - x[0])
        ans = 0

        for act, req in tasks:
            ans = max(ans + act, req)

        return ans