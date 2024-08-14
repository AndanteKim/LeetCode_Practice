class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        ans, bank, n = float("inf"), set(bank), len(startGene)
        visited = set()
        
        queue = deque([(startGene, 0)])
        while queue:
            curr_gene, steps = queue.popleft()
            
            if curr_gene == endGene:
                ans = min(ans, steps)
            
            structure = list(curr_gene)
            for i in range(n):
                temp = structure[i]
                for c in ('A', 'C', 'G', 'T'):
                    if structure[i] != c:
                        structure[i] = c
                        mutation = "".join(structure)
                        if mutation in bank and mutation not in visited:
                            queue.append((mutation, steps + 1))
                            visited.add(mutation)
                        structure[i] = temp
        
        return -1 if ans == float("inf") else ans