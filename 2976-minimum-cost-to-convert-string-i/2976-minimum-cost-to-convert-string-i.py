class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        # Create a graph representation of character conversions
        adj = [[] for _ in range(26)]
        
        # Populate the adjacency list with character conversions
        conversion_count = len(original)
        for i in range(conversion_count):
            adj[ord(original[i]) - 97].append((ord(changed[i]) - 97, cost[i]))
        
        # Calculate the shortest paths for all possible character conversions
        min_conv_costs = [self._dijkstra(i, adj) for i in range(26)]
        
        # Calculate the total cost of converting source to target
        total_cost = 0
        for s, t in zip(source, target):
            if s != t:
                char_conv_cost = min_conv_costs[ord(s) - 97][ord(t) - 97]
                
                if char_conv_cost == float("inf"):
                    return -1   # Conversion not possible
                
                total_cost += char_conv_cost
                
        return total_cost
    
    def _dijkstra(self, s_char: int, adj: List[List[tuple]]) -> List[int]:
        # Priority queue to store characters with their conversion cost, sorted by cost
        pq = [(0, s_char)]
        
        # List to store the minimum conversion cost to each character
        min_costs = [float("inf")] * 26
        
        while pq:
            curr_cost, curr_c = heappop(pq)
            
            if min_costs[curr_c] != float("inf"):
                continue
                
            min_costs[curr_c] = curr_cost
            
            # Explore all possible conversions from the current character
            for t_char, conv_cost in adj[curr_c]:
                new_cost = curr_cost + conv_cost
                
                # If we found a cheaper conversion, update its cost
                if min_costs[t_char] == float("inf"):
                    heappush(pq, (new_cost, t_char))
        
        # Return the list of minimum conversion costs from the starting character to all others.
        return min_costs