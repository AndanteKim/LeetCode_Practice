class Solution:
    
    def equationsPossible(self, equations: List[str]) -> bool:
        root = list(range(26))
        
        def find(x: int) -> int:
            if x != root[x]:
                root[x] = find(root[x])
            return root[x]
        
        def union(x: int, y: int) -> None:
            x, y = find(x), find(y)
            root[x] = y
        
        for eqn in equations:
            if eqn[1] == '=':
                x, y = ord(eqn[0]) - ord('a'), ord(eqn[3]) - ord('a')
                union(x, y)
        
        for eqn in equations:
            if eqn[1] == '!':
                x, y = ord(eqn[0]) - ord('a'), ord(eqn[3]) - ord('a')
                if find(x) == find(y):
                    return False
        return True