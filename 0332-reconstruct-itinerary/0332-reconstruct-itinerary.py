class Solution:
    def backtrack(self, origin: str, route: list, visited: Dict[str, list], graph: Dict[str, list]) -> bool:
        if len(route) == self.flights + 1:
            self.ans = route
            return True
        
        for i, nextDst in enumerate(graph[origin]):
            if not visited[origin][i]:
                # mark the visit before the next recursion
                visited[origin][i] = True
                ret = self.backtrack(nextDst, route + [nextDst], visited, graph)
                visited[origin][i] = False
                if ret:
                    return True
                
        return False
    
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)
        
        for origin, dest in tickets:
            graph[origin].append(dest)
        
        visited = dict()
        # sort the itinerary based on the lexical order
        for origin, itinerary in graph.items():
            itinerary.sort()
            visited[origin] = [False] * len(itinerary)
        
        self.flights, self.ans = len(tickets), []
        route = ['JFK']
        self.backtrack('JFK', route, visited, graph)
        
        return self.ans