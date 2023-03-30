class Solution:
    
    def dfs(self, node: int, rooms: List[List[int]], visited: List[int]) -> None:
        visited[node] = True
        for key in rooms[node]:
            if not visited[key]:
                self.dfs(key, rooms, visited)
        
    
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        visited = [False] * n
        self.dfs(0, rooms, visited)
                
        return all(visited)