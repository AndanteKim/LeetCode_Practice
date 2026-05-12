class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key = lambda x: x[1] - x[0], reverse = True)
        ans = remain = 0

        for act, req in tasks:
            if remain <= req:
                ans += req - remain
            remain = max(req - act, remain - act)

        return ans