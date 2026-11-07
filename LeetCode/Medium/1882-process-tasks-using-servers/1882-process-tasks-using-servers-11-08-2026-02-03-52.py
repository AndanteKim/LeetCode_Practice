class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        def release():
            while busy and busy[0][0] <= ts:
                _, idx = heappop(busy)
                heappush(idle, (servers[idx], idx))
        
        idle = [(s, i) for i, s in enumerate(servers)]
        heapify(idle)

        busy, ts = [], 0
        ans = []
        
        for i, task in enumerate(tasks):
            ts = max(ts, i)
            release()
            if not idle:
                ts = busy[0][0]
                release()
            
            _, idx = heappop(idle)
            ans.append(idx)
            heappush(busy, (ts + task, idx))

        return ans