class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        # Initialize result to store the total minimum cost
        total_cost = 0
        
        # Initialize a 2D list to store the minimum transformation cost
        # between any two characters
        min_cost = [[float("inf")] * 26 for _ in range(26)]
        
        # Fill the initial transformation costs from the given original,
        # changed, and cost arrays
        for orig, chg, cst in zip(original, changed, cost):
            start_c, end_c = ord(orig) - 97, ord(chg) - 97
            min_cost[start_c][end_c] = min(min_cost[start_c][end_c], cst)
            
        # Use Floyd-Warshall algorithm to find the shortest path between any
        # two characters
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    min_cost[i][j] = min(min_cost[i][j], min_cost[i][k] + min_cost[k][j])
                    
        # Calculate the total minimum cost to transform the source string to
        # the target string
        for src, tgt in zip(source, target):
            if src == tgt:
                continue
            source_c, target_c = ord(src) - 97, ord(tgt) - 97
            
            # If the trnasformation is not possible, return -1
            if min_cost[source_c][target_c] == float("inf"):
                return -1
            total_cost += min_cost[source_c][target_c]
            
        return total_cost