class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        graph, n = defaultdict(list), len(pid)

        for i in range(n):
            graph[ppid[i]].append(pid[i])    
        
        ans, queue = [], deque([kill])

        while queue:
            node = queue.popleft()
            ans.append(node)

            for child in graph[node]:
                queue.append(child)

        return ans