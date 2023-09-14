class Solution:
    def dfs(self, origin: str, ans: List[str], graph: Dict[str, list]) -> None:
        destList = graph[origin]
        while destList:
            # while we visit the edge, we trim it off from graph
            nextDst = destList.pop()
            self.dfs(nextDst, ans, graph)
        ans.append(origin)
    
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)
        
        for origin, dest in tickets:
            graph[origin].append(dest)
            
        for origin, itinerary in graph.items():
            itinerary.sort(reverse = True)
        
        ans = []
        self.dfs("JFK", ans, graph)
        return ans[::-1]