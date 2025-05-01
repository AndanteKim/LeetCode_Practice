from sortedcontainers import SortedList

class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        def check(mid: int) -> bool:
            p = pills
            # Ordered set of workers
            ws = SortedList(workers[m - mid : ])
            # Enumerate each task from largest to smallest
            for i in range(mid - 1, -1, -1):
                # If the largest element in the ordered set is greater than or equal to tasks[i]
                if ws[-1] >= tasks[i]:
                    ws.pop()
                else:
                    if p == 0:
                        return False
                    rep = ws.bisect_left(tasks[i] - strength)
                    if rep == len(ws):
                        return False
                    p -= 1
                    ws.pop(rep)
            
            return True
        
        workers.sort()
        tasks.sort()

        ans, n, m = 0, len(tasks), len(workers)
        left, right = 1, min(m, n)

        while left <= right:
            mid = left + ((right - left) >> 1)
            if check(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1

        return ans