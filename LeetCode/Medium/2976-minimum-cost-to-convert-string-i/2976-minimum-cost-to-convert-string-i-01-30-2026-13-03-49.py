class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        def _dijkstra(start_char: int) -> List[int]:
            # Priority queue to store characters with their conversion cost, sorted by cost
            pq = [(0, start_char)]

            # List to store the minimum conversion cost to each character
            min_costs = [float("inf")] * 26

            while pq:
                curr_cost, curr_char = heappop(pq)
                if min_costs[curr_char] != float("inf"):
                    continue
                
                min_costs[curr_char] = curr_cost

                # Explore all possible conversions from the current character
                for target_char, conversion_cost in adj_list[curr_char]:
                    new_total_cost = curr_cost + conversion_cost

                    # If we found a cheaper conversion, update its cost
                    if min_costs[target_char] == float("inf"):
                        heappush(pq, (new_total_cost, target_char))
                
            return min_costs
        
        # Create a graph
        adj_list = [[] for _ in range(26)]

        # Populate the adjacency list with character conversions
        n = len(original)

        for i in range(n):
            adj_list[ord(original[i]) - 97].append(
                (ord(changed[i]) - 97, cost[i])
            )
        
        # Calculate shortest paths for all possible character conversions
        min_conversion_costs = [
            _dijkstra(i) for i in range(26)
        ]

        # Calculate teh total cost of converting source to target
        total_cost = 0
        for s, t in zip(source, target):
            if s != t:
                conversion_cost = min_conversion_costs[ord(s) - 97][ord(t) - 97]

                if conversion_cost == float("inf"):
                    return -1   # Conversion not possible
                total_cost += conversion_cost

        return total_cost