class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        
        if n <= 1:
            return 0

        graph = defaultdict(list)

        for i in range(n):
            graph[arr[i]].append(i)
        
        # Store current layers
        currs, visited, ans = [0], {0}, 0

        while currs:
            nxt = []

            for node in currs:
                if node == n - 1:
                    return ans
                
                for child in graph[arr[node]]:
                    if child in visited:
                        continue
                    visited.add(child)
                    nxt.append(child)

                graph[arr[node]].clear()

                for child in [node - 1, node + 1]:
                    if 0 <= child < n and child not in visited:
                        visited.add(child)
                        nxt.append(child)
            currs = nxt
            ans += 1

        return -1