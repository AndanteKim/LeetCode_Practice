class Solution:
    def dfs(self, start: int, visited: List[bool], rooms: List[List[int]]) -> None:
        if not visited[start]:
            visited[start] = True
            for neighbor in rooms[start]:
                self.dfs(neighbor, visited, rooms)
    
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        visited = [False] * n
        
        self.dfs(0, visited, rooms)
        
        return all(visited)