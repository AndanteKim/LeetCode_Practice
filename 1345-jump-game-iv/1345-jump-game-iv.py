class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        if n <= 1: return 0
        
        graph = defaultdict(list)
        for i in range(n):
            graph[arr[i]].append(i)
        
        curs = set([0])
        visited = {0, n - 1}
        step = 0
        
        other = set([n - 1])
        
        while curs:
            if len(curs) > len(other):
                curs, other = other, curs
            nex = set()
            
            for node in curs:
                for child in graph[arr[node]]:
                    if child in other:
                        return step + 1
                    
                    if child not in visited:
                        visited.add(child)
                        nex.add(child)
                
                graph[arr[node]].clear()
                
                for child in [node - 1, node + 1]:
                    if child in other:
                        return step + 1
                    
                    if 0 <= child < len(arr) and child not in visited:
                        visited.add(child)
                        nex.add(child)
            
            curs = nex
            step += 1
        
        return -1