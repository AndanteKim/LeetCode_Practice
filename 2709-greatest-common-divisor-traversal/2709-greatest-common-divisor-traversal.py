class Graph:
    def __init__(self, n: int):
        self.n = n
        self.edges = [[] for _ in range(n)]
        
    def traverse(self, x: int, visited: List[bool]) -> None:
        visited[x] = True
        for y in self.edges[x]:
            if not visited[y]:
                self.traverse(y, visited)
                
    def add_edge(self, x: int, y: int) -> None:
        self.edges[y].append(x)
        self.edges[x].append(y)
        
    def is_connected(self) -> bool:
        visited = [False for _ in range(self.n)]
        self.traverse(0, visited)
        return visited.count(True) == self.n

class Solution:
    def get_prime_factors(self, x: int) -> int:
        for i in range(2, int(sqrt(x)) + 1):
            if x % i == 0:
                while x % i == 0:
                    x //= i
                yield i
        
        if x != 1:
            yield x
    
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        # DFS
        n = len(nums)
        if n == 1:
            return True
        
        g = Graph(n)
        seen = dict()
        for i in range(n):
            if nums[i] == 1:
                return False
            
            for prime in self.get_prime_factors(nums[i]):
                if prime in seen:
                    g.add_edge(i, seen[prime])
                else:
                    seen[prime] = i
        
        return g.is_connected()