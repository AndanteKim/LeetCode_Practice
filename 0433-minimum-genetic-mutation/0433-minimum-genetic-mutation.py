class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        queue = deque([(startGene, 0)])
        seen, n = {startGene}, len(startGene)
        
        while queue:
            curr, steps = queue.popleft()
            if curr == endGene:
                return steps
            
            for c in "ACGT":
                for i in range(n):
                    neighbor = curr[:i] + c + curr[i + 1:]
                    
                    if neighbor not in seen and neighbor in bank:
                        queue.append((neighbor, steps + 1))
                        seen.add(neighbor)
                        
        return -1