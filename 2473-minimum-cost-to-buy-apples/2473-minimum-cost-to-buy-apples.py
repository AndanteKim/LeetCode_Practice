class Solution:
    def minCost(self, n: int, roads: List[List[int]], appleCost: List[int], k: int) -> List[int]:
        # Find the minimum cost to buy an apple from the start city
        def shortest_path(start_city: int) -> int:
            # Stores the travel cost reach each city from the start city
            travel_costs = [float('inf') for _ in range(n)]
            travel_costs[start_city] = 0
            
            # Initialize the heap (priority queue) with the starting city
            # Each element of the heap is a tuple with the cost and city
            heap, min_cost = [(0, start_city)], float('inf')
            
            while heap:
                # Remove the city with the minimum cost from the top of the heap
                travel_cost, curr_city = heappop(heap)
                
                # Update the min cost if the curr city has a small total cost
                min_cost = min(min_cost, appleCost[curr_city] + (k + 1) * travel_cost)
                
                # Add each neighboring city to the heap if an apple is cheaper
                for neighbor, cost in graph[curr_city]:
                    next_cost = travel_cost + cost
                    if next_cost < travel_costs[neighbor]:
                        travel_costs[neighbor] = next_cost
                        heappush(heap, (next_cost, neighbor))
            return min_cost
        
        # Store the graph as a list of lists
        # The rows represent the cities
        # The columns store an adjacency list of road, cost pairs (edge, weight)
        graph = [[] for _ in range(n)]
        
        # Add each road to the graph using adjacency lists
        # Store each city at 'graph[city - 1]'
        for start, end, cost in roads:
            graph[start - 1].append((end - 1, cost))
            graph[end - 1].append((start - 1, cost))
            
        # Find the minimum cost to buy an apple starting in each city
        ans = []
        for start_city in range(n):
            ans.append(shortest_path(start_city))
        
        return ans