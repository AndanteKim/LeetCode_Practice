class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        
        bank, seen, ans = set(bank), set(), float('inf')
        queue = deque([(startGene, 0)])
        seen.add(startGene)
        
        while queue:
            gene, mutations = queue.popleft()
            
            if gene == endGene:
                return mutations
                
            for digit in range(8):
                for char in ('A', 'C', 'G', 'T'):
                    new_gene = gene[:digit] + char + gene[digit + 1:]
                    if new_gene not in seen and new_gene in bank:
                        seen.add(new_gene)
                        queue.append((new_gene, mutations + 1))
                                 
        return -1 if ans == float('inf') else ans